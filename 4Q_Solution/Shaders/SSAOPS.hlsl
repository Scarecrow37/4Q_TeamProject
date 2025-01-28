#include "PostProcess.hlsli"
#include "ShaderUtilities.hlsli"

float GetBloomCurve(float intensity, float threshold)
{
    float result = intensity;
    intensity *= 2;
    result = max(0, intensity - threshold);
    result *= result;
    return result * 0.5;
}

float4 main(PS_INPUT input) : SV_Target
{
    float occlusion = 0.0;
    int kernelSize = 16; // ���� Ŀ�� ũ��
    float3 noiseScale = float3(1920.0 / 4.0, 1080.0 / 4.0, 0.0);


    for (int i = 0; i < kernelSize; ++i)
    {
        // ���� ��ġ
        float3 samplePos = fragPos + kernel[i] * radius;

        // ������ Ŭ�� �������� ��ȯ
        float4 offset = proj * float4(samplePos, 1.0);
        offset.xyz /= offset.w; // NDC�� ��ȯ
        offset.xyz = offset.xyz * 0.5 + 0.5; // [0,1] ������ ��ȯ

        // ���� ��
        float sampleDepth = texture(depthTex, offset.xy).r;
        float rangeCheck = smoothstep(0.0, 1.0, radius / abs(fragPos.z - sampleDepth));
        occlusion += (sampleDepth >= samplePos.z ? 1.0 : 0.0) * rangeCheck;
    }

    occlusion = 1.0 - (occlusion / kernelSize); // �����Ͽ� ���� ���
    return occlusion;
}