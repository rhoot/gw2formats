// File: gw2formats/TextureFile.h

#pragma once

#ifndef GW2FORMATS_TEXTUREFILE_H_INCLUDED
#define GW2FORMATS_TEXTUREFILE_H_INCLUDED

#include <string>
#include <vector>

#include <gw2formats/base.h>

namespace gw2f
{

class ITextureData
{
public:
    virtual ~ITextureData() {}
    virtual uint16 width() const = 0;
    virtual uint16 height() const = 0;
    virtual uint32 format() const = 0;
    virtual const byte* data() const = 0;
    virtual uint32 size() const = 0;
};

GW2FORMATS_API class TextureFile
{
    std::vector<ITextureData*> m_data;
public:
    TextureFile();
    TextureFile(const byte* p_data, uint32 p_size);
    TextureFile(const std::string& p_filename);
    TextureFile(const TextureFile& p_other);
    ~TextureFile();

    TextureFile& operator=(const TextureFile& p_other);

    bool load(const std::string& p_filename);
    bool assign(const byte* p_data, uint32 p_size);
    void clear();

    uint16 width() const;
    uint16 height() const;
    uint32 format() const;

    uint32 mipMapCount() const;
    const ITextureData& mipMapLevel(uint32 p_level) const;
};

}; // namespace gw2f

#endif // GW2FORMATS_TEXTUREFILE_H_INCLUDED
