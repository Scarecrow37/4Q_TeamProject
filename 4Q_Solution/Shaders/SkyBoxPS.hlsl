struct PS_INPUT
{
    float4 position      : SV_POSITION;
    float3 worldPosition : POSITION;
};

struct PS_OUTPUT
{
    float4 color : SV_Target0;
    float depth  : SV_Depth;
};

TextureCube txDiffuse        : register(t0);

SamplerState samLinear_wrap  : register(s0);

PS_OUTPUT main(PS_INPUT input)
{
    PS_OUTPUT output = (PS_OUTPUT) 0;
    
    float3 envVector = normalize(input.worldPosition);
    output.color = txDiffuse.SampleLevel(samLinear_wrap, envVector, 0);
    output.depth = 1;
    
    return output;
}