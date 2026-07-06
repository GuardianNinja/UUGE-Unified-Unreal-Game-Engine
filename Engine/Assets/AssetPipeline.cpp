#include "AssetPipeline.h"

AssetID AssetPipeline::ImportAsset(const std::string& path, const std::string& type)
{
    AssetMetadata metadata;
    metadata.Id = NextAssetId++;
    metadata.Path = path;
    metadata.Type = type;
    Cache[metadata.Id] = metadata;
    return metadata.Id;
}

const AssetMetadata* AssetPipeline::GetAsset(AssetID id) const
{
    auto it = Cache.find(id);
    if (it == Cache.end())
    {
        return nullptr;
    }

    return &it->second;
}

std::size_t AssetPipeline::GetImportedAssetCount() const
{
    return Cache.size();
}
