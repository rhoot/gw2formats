// File: pf/chunks/cntc/PackContent.cpp

#include <gw2formats/pf/chunks/cntc/PackContent.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackContentManifestV0
//============================================================================/

PackContentManifestV0::PackContentManifestV0()
{
}

PackContentManifestV0::PackContentManifestV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackContentManifestV0::PackContentManifestV0(const PackContentManifestV0& p_other)
    : data(p_other.data)
{
}

PackContentManifestV0& PackContentManifestV0::operator=(const PackContentManifestV0& p_other)
{
    data = p_other.data;
    return *this;
}

const byte* PackContentManifestV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, data);
    return p_data;
}

//============================================================================/
//      PackContentNamespaceV0
//============================================================================/

PackContentNamespaceV0::PackContentNamespaceV0()
    : domain(0)
{
}

PackContentNamespaceV0::PackContentNamespaceV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackContentNamespaceV0::PackContentNamespaceV0(const PackContentNamespaceV0& p_other)
    : name(p_other.name)
    , domain(p_other.domain)
    , data(p_other.data)
{
}

PackContentNamespaceV0& PackContentNamespaceV0::operator=(const PackContentNamespaceV0& p_other)
{
    name   = p_other.name;
    domain = p_other.domain;
    data   = p_other.data;
    return *this;
}

const byte* PackContentNamespaceV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, name);
    p_data = helpers::read(p_data, p_size, domain);
    p_data = helpers::read(p_data, p_size, data);
    return p_data;
}

//============================================================================/
//      PackContentV0
//============================================================================/

PackContentV0::PackContentV0()
    : flags(0)
{
}

PackContentV0::PackContentV0(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackContentV0::PackContentV0(const PackContentV0& p_other)
    : flags(p_other.flags)
    , manifest(p_other.manifest)
    , namespaces(p_other.namespaces)
    , fileRefs(p_other.fileRefs)
{
}

PackContentV0& PackContentV0::operator=(const PackContentV0& p_other)
{
    flags      = p_other.flags;
    manifest   = p_other.manifest;
    namespaces = p_other.namespaces;
    fileRefs   = p_other.fileRefs;
    return *this;
}

const byte* PackContentV0::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, flags);
    p_data = helpers::read(p_data, p_size, manifest);
    p_data = helpers::read(p_data, p_size, namespaces);
    p_data = helpers::read(p_data, p_size, fileRefs);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
