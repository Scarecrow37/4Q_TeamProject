#include "ShaderUtilities.hlsli"
#include "Lighting.hlsli"

struct PS_INPUT
{
    float4 position         : SV_POSITION;
    float3 worldPosition    : POSITION0;
    float4 shadowPosition   : POSITION1;
    float3 normal           : NORMAL;
    float3 tangent          : TANGENT;
    float3 biTangent        : BITANGENT;
    float2 uv               : TEXCOORD;
};

Texture2D txDiffuse          : register(t0);
Texture2D txNormal           : register(t1);
Texture2D txSpecular         : register(t2);
Texture2D txEmissive         : register(t3);
Texture2D txOpacity          : register(t4);
Texture2D txLight            : register(t5);
Texture2D txMetalness        : register(t6);
Texture2D txRoughness        : register(t7);

#define PBR
#define IBL
#define Shadow

float4 main(PS_INPUT input) : SV_Target
{
    float3 normalTex = txNormal.Sample(samLinear_wrap, input.uv).xyz;
    float3x3 TBN = float3x3(input.tangent, input.biTangent, input.normal);
    float3 N = normalize(mul(normalTex * 2.0f - 1.0f, TBN));
    
    float3 albedo = GammaToLinearSpace(txDiffuse.Sample(samLinear_wrap, input.uv).rgb);
    float  alpha = 1.0;
    
    float3 directLighting = 0;
    float3 ambientLighting = 0;
    float  shadowFactor = 1.0;
    
    float3 V = normalize(cameraPosition - input.worldPosition);

#ifdef PBR
    float roughness = txRoughness.Sample(samLinear_wrap, input.uv).r;
    float metalness = txMetalness.Sample(samLinear_wrap, input.uv).r;
    
    // PBR_Directional
    directLighting += DirectionalLightPBR(input.worldPosition, N, V, albedo, roughness, metalness);

    // PBR_Point
    directLighting += PointLightPBR(input.worldPosition, N, V, albedo, roughness, metalness);
#endif
    
#ifdef IBL
    //float3 irradiance = txIBL_Diffuse.Sample(samLinear_wrap, N).rgb;
    
    //uint specularTextureLevels = QuerySpecularTextureLevels(txIBL_Specular);
    //float3 Lr = 2.0 * NdotV * N - V;
    //float3 preFilteredColor = txIBL_Specular.SampleLevel(samLinear_wrap, Lr, roughness * specularTextureLevels).rgb;
    //float2 brdf = txIBL_BRDF.Sample(samLinear_clamp, float2(NdotV, roughness)).rg;
        
    //F = FresnelReflection(NdotV, F0);
    //kd = lerp(1.0 - F, 0, metalness);
    //float3 diffuseIBL = kd * albedo * irradiance;
    //float3 specularIBL = (F0 * brdf.x + brdf.y) * preFilteredColor;
    
    //ambientLighting = diffuseIBL + specularIBL;
#endif
   
#ifdef Shadow
    float currentShadowDepth = input.shadowPosition.z / input.shadowPosition.w;
    float2 uv = input.shadowPosition.xy / input.shadowPosition.w;    
    uv.y = -uv.y;
    uv = uv * 0.5 + 0.5;
    
    if (uv.x >= 0 && uv.x <= 1 && uv.y >= 0 && uv.y <= 1)
    {
        float2 offsets[9] =
        {
            float2(-1, -1), float2(0, -1), float2(1, -1),
            float2(-1, 0), float2(0, 0), float2(1, 0),
            float2(-1, 1), float2(0, 1), float2(1, 1)
        };
        
        shadowFactor = 0;
    
        [unroll]
        for (int i = 0; i < 9; i++)
        {
            float2 sampleUV = uv + offsets[i] * texel;
            float bias = 0.001f;
            shadowFactor += txShadowDepth.SampleCmpLevelZero(samComparison, sampleUV, currentShadowDepth - bias);
        }
        
        shadowFactor = shadowFactor / 9.0;
    }    
    
#endif
    
    float4 color = 0;
    color.rgb = shadowFactor * (directLighting + ambientLighting);
    color.a = alpha;
        
    float4 opacity = txOpacity.Sample(samLinear_wrap, input.uv);
    if (length(opacity))
        color.a = opacity.a;

    if (color.a < 0.01)
        discard;
    
    color.rgb = LinearToGammaSpace(color.rgb);
    
    float4 emissive = txEmissive.Sample(samLinear_wrap, input.uv);
    color += emissive;
    
    return color;
}