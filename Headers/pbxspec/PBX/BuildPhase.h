// Copyright 2013-present Facebook. All Rights Reserved.

#ifndef __pbxspec_PBX_BuildPhase_h
#define __pbxspec_PBX_BuildPhase_h

#include <pbxspec/PBX/Specification.h>

namespace pbxspec { namespace PBX {

class BuildPhase : public Specification {
public:
    typedef std::shared_ptr <BuildPhase> shared_ptr;
    typedef std::vector <shared_ptr> vector;

public:
    class BuildRule {
        typedef std::shared_ptr <BuildRule> shared_ptr;
        typedef std::vector <shared_ptr> vector;

    protected:
        std::string _name;
        std::string _fileType;
        std::string _compilerSpec;

    protected:
        friend class BuildPhase;
        BuildRule();

    public:
        inline std::string const &name() const
        { return _name; }
        inline std::string const &fileType() const
        { return _fileType; }
        inline std::string const &compilerSpec() const
        { return _compilerSpec; }

    protected:
        bool parse(plist::Dictionary const *dict);
    };

protected:
    BuildRule::vector _buildRules;

protected:
    BuildPhase(bool isDefault);

public:
    virtual ~BuildPhase();

public:
    inline char const *type() const override
    { return BuildPhase::Type(); }

public:
    inline BuildPhase::shared_ptr const &base() const
    { return reinterpret_cast <BuildPhase::shared_ptr const &> (Specification::base()); }

public:
    inline BuildRule::vector const &buildRules() const
    { return _buildRules; }

protected:
    friend class Specification;
    bool parse(plist::Dictionary const *dict) override;

protected:
    bool inherit(Specification::shared_ptr const &base) override;
    virtual bool inherit(BuildPhase::shared_ptr const &base);

protected:
    static BuildPhase::shared_ptr Parse(plist::Dictionary const *dict);

public:
    static inline char const *Isa()
    { return ISA::PBXBuildPhase; }
    static inline char const *Type()
    { return Types::BuildPhase; }
};

} }

#endif  // !__pbxspec_PBX_BuildPhase_h