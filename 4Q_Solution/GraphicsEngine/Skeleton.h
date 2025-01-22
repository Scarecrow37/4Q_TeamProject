#pragma once
#include "Base.h"

struct Bone
{
	Matrix local;
	Matrix offset;
	std::string name;
	std::vector<Bone> children;
	int id;
};

class Skeleton : public Base
{
public:
	explicit Skeleton() = default;
	virtual ~Skeleton() = default;

public:
	Bone* GetBone(const unsigned int ID) const { return _bones[ID]; }

public:
	void Initialize(const aiScene* paiScene, std::unordered_map<std::string, std::pair<unsigned int, Matrix>>& boneInfo);
	void SetUpSplitBone(const unsigned int maxSplit);
	void SplitBone(const unsigned int ID, const char* boneName);

private:
	bool LoadSkeleton(Bone& bone, aiNode* paiNode, std::unordered_map<std::string, std::pair<unsigned int, Matrix>>& boneInfo);

private:
	// Base을(를) 통해 상속됨
	void Free() override;

private:
	Bone _rootBone;
	std::vector<Bone*> _bones;
};