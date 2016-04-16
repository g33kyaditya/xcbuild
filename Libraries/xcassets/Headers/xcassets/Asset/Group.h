/* Copyright 2013-present Facebook. All Rights Reserved. */

#ifndef __xcassets_Asset_Group_h
#define __xcassets_Asset_Group_h

#include <xcassets/Asset/Asset.h>
#include <plist/Dictionary.h>

#include <memory>
#include <string>
#include <vector>
#include <ext/optional>

namespace xcassets {
namespace Asset {

class Group : public Asset {
private:
    std::vector<std::shared_ptr<Asset>>     _children;

private:
    ext::optional<std::vector<std::string>> _onDemandResourceTags;
    ext::optional<bool>                     _providesNamespace;

private:
    friend class Asset;
    using Asset::Asset;

public:
    std::vector<std::shared_ptr<Asset>> children() const
    { return _children; }

public:
    ext::optional<std::vector<std::string>> const &onDemandResourceTags() const
    { return _onDemandResourceTags; }
    bool providesNamespace() const
    { return _providesNamespace.value_or(false); }
    ext::optional<bool> providesNamespaceOptional() const
    { return _providesNamespace; }

public:
    static AssetType Type()
    { return AssetType::Group; }
    virtual AssetType type()
    { return AssetType::Group; }

public:
    /*
     * Groups have no extension.
     */
    static ext::optional<std::string> Extension()
    { return ext::nullopt; }

protected:
    virtual bool parse(plist::Dictionary const *dict, std::unordered_set<std::string> *seen, bool check);
};

}
}

#endif // !__xcassets_Asset_Group_h

