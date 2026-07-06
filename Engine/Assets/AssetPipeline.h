#pragma once

#include <cstdint>
#include <string>
#include <unordered_map>

using AssetID = std::uint32_t;

struct AssetMetadata
{
    AssetID Id = 0;
    std::string Path;
    std::string Type;
};

class AssetPipeline
{
public:
    AssetID ImportAsset(const std::string& path, const std::string& type);
    const AssetMetadata* GetAsset(AssetID id) const;
    std::size_t GetImportedAssetCount() const;

private:
    AssetID NextAssetId = 1;
    std::unordered_map<AssetID, AssetMetadata> Cache{};
};
