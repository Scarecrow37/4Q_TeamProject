#include "pch.h"
#include "DSHLoadManager.h"

void Engine::DSHLoad::Manager::Initialize()
{
}

void Engine::DSHLoad::Manager::Finalize()
{
}

Engine::Load::ConfigData Engine::DSHLoad::Manager::GetGameConfigData()
{
	return Load::ConfigData(&_gameConfigData);
}

void Engine::DSHLoad::Manager::LoadRegisterData(const std::filesystem::path& path)
{
	for (nlohmann::json data = nlohmann::json::parse(std::ifstream(path)); const auto& objectData: data["registInfo"]["regists"])
	{
		std::string objectClassNameData = objectData["className"].get<std::string>();
		std::wstring objectClassName;
		objectClassName.assign(objectClassNameData.begin(), objectClassNameData.end());
		std::string fbxPathData = objectData["fbxPath"].get<std::string>();
		std::filesystem::path fbxPath(fbxPathData);
		_objectRegisterData[objectClassName][L"fbxPath"] = fbxPath;
	}
}

void Engine::DSHLoad::Manager::LoadCloneData(const std::filesystem::path& path)
{
	for (nlohmann::json data = nlohmann::json::parse(std::ifstream(path)); const auto& objectData : data["objectGroup"]["groups"])
	{
		for (const auto& modelData : objectData["models"])
		{
			std::string objectClassNameData = modelData["className"].get<std::string>();
			std::wstring objectClassName;
			objectClassName.assign(objectClassNameData.begin(), objectClassNameData.end());

			bool isPublic = modelData["publicObject"].get<bool>();

			const auto& position = modelData["transformData"]["position"];
			Math::Vector3 positionData = { position["x"].get<float>(), position["y"].get<float>(), position["z"].get<float>() };

			const auto& rotation = modelData["transformData"]["rotation"];
			Math::Quaternion rotationData = { rotation["x"].get<float>(), rotation["y"].get<float>(), rotation["z"].get<float>(), rotation["w"].get<float>() };

			const auto& scale = modelData["transformData"]["scale"];
			Math::Vector3 scaleData = { scale["x"].get<float>(), scale["y"].get<float>(), scale["z"].get<float>() };

			Properties cloneData
			{
				std::pair<const std::wstring, std::any>{L"isPublic", isPublic},
				std::pair<const std::wstring, std::any>{L"position", positionData},
				std::pair<const std::wstring, std::any>{L"rotation", rotationData},
				std::pair<const std::wstring, std::any>{L"scale", scaleData}
			};
			_objectCloneData[objectClassName].push_back(cloneData);
		}
	}
}

std::optional<Engine::Load::ConfigData> Engine::DSHLoad::Manager::GetObjectRegisterData(const std::wstring& name)
{
	if (const auto configData = _objectRegisterData.find(name); configData == _objectRegisterData.end())
		return std::nullopt;
	else return Load::ConfigData(&configData->second);
}

std::vector<Engine::Load::ConfigData> Engine::DSHLoad::Manager::GetObjectCloneData(const std::wstring& name)
{
	std::vector<Load::ConfigData> result;
	if (const auto configData = _objectCloneData.find(name); configData != _objectCloneData.end())
	{
		for (auto& data : configData->second)
		{
			result.emplace_back(&data);
		}
	}
	return result;
}

