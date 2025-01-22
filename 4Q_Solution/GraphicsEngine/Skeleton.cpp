#include "pch.h"
#include "Skeleton.h"

void Skeleton::Initialize(const aiScene* paiScene, std::unordered_map<std::string, std::pair<unsigned int, Matrix>>& boneInfoTable)
{
	LoadSkeleton(_rootBone, paiScene->mRootNode, boneInfoTable);
	_bones.push_back(&_rootBone);
}

void Skeleton::SetUpSplitBone(const unsigned int maxSplit)
{
	_bones.clear();
	_bones.resize(maxSplit);
}

void Skeleton::SplitBone(const unsigned int ID, const char* boneName)
{	
	std::queue<Bone*> bfs;
	bfs.push(&_rootBone);

	while (!bfs.empty())
	{
		Bone* bone = bfs.front();
		bfs.pop();

		if (bone->name == boneName)
		{
			_bones[ID] = bone;
			break;
		}

		for (auto& child : bone->children)
			bfs.push(&child);
	}
}

bool Skeleton::LoadSkeleton(Bone& bone, aiNode* paiNode, std::unordered_map<std::string, std::pair<unsigned int, Matrix>>& boneInfoTable)
{
	if (boneInfoTable.find(paiNode->mName.C_Str()) != boneInfoTable.end())
	{
		bone.name = paiNode->mName.C_Str();
		bone.id = boneInfoTable[bone.name].first;
		bone.offset = boneInfoTable[bone.name].second;
		bone.local = XMMatrixTranspose(XMMATRIX(&paiNode->mTransformation.a1));

		for (unsigned int i = 0; i < paiNode->mNumChildren; i++)
		{
			Bone child;
			if (LoadSkeleton(child, paiNode->mChildren[i], boneInfoTable))
			{
				bone.children.push_back(child);
			}
		}
		return true;
	}
	else
	{
		for (unsigned int i = 0; i < paiNode->mNumChildren; i++)
		{
			if (LoadSkeleton(bone, paiNode->mChildren[i], boneInfoTable))
			{
				return true;
			}
		}
	}

	return false;
}

void Skeleton::Free()
{
}
