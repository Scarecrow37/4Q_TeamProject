struct VS_INPUT
{
    float4 position : POSITION;
    float2 uv       : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 position : SV_POSITION;
    float2 uv       : TEXCOORD0;
};

VS_OUTPUT main(VS_INPUT input)
{
    VS_OUTPUT output = (VS_OUTPUT)0;
    
    output.position = input.position;
    output.uv = input.uv;
    
    return output;
}