/* Copyright 2013-present Facebook. All Rights Reserved. */

#ifndef __xcassets_Asset_Catalog_h
#define __xcassets_Asset_Catalog_h

#include <xcassets/Asset/Asset.h>

namespace xcassets {
namespace Asset {

class Catalog : public Asset {
private:
    std::vector<std::shared_ptr<Asset>> _children;

private:
    friend class Asset;
    using Asset::Asset;

public:
    std::vector<std::shared_ptr<Asset>> children() const
    { return _children; }

public:
    static AssetType Type()
    { return AssetType::Catalog; }
    virtual AssetType type()
    { return AssetType::Catalog; }

public:
    static ext::optional<std::string> Extension()
    { return std::string("xcassets"); }

protected:
    virtual bool parse(plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check);
};

}
}

#endif // !__xcassets_Asset_Catalog_h
