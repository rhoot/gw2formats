// File: TextureFile.cpp

#include <gw2formats/TextureFile.h>

#include <algorithm>
#include <fstream>

namespace gw2f
{
namespace 
{

class TextureData
    : public ITextureData
{
    uint16 m_width;
    uint16 m_height;
    uint32 m_format;
    std::vector<byte> m_data;
public:
    TextureData(uint16 p_width, uint16 p_height, uint32 p_format, const byte* p_data, uint32 p_size);
    TextureData(const ITextureData& p_other);
    virtual ~TextureData();
    virtual uint16 width() const override;
    virtual uint16 height() const override;
    virtual uint32 format() const override;
    virtual const byte* data() const override;
    virtual uint32 size() const override;
};

TextureData::TextureData(uint16 p_width, uint16 p_height, uint32 p_format, const byte* p_data, uint32 p_size)
    : m_width(p_width)
    , m_height(p_height)
    , m_format(p_format)
    , m_data(p_size)
{
    std::copy_n(p_data, p_size, m_data.data());
}

TextureData::TextureData(const ITextureData& p_other)
    : m_width(p_other.width())
    , m_height(p_other.height())
    , m_format(p_other.format())
    , m_data(p_other.size())
{
    std::copy_n(p_other.data(), p_other.size(), m_data.data());
}

TextureData::~TextureData()
{
}

uint16 TextureData::width() const
{
    return m_width;
}

uint16 TextureData::height() const
{
    return m_height;
}

uint32 TextureData::format() const
{
    return m_format;
}

const byte* TextureData::data() const
{
    return m_data.data();
}

uint32 TextureData::size() const
{
    return m_data.size();
}

}; // anon namespace

TextureFile::TextureFile()
{
}

TextureFile::TextureFile(const byte* p_data, uint32 p_size)
{
    assign(p_data, p_size);
}

TextureFile::TextureFile(const std::string& p_filename)
{
    load(p_filename);
}

TextureFile::TextureFile(const TextureFile& p_other)
{
    *this = p_other;
}

TextureFile::~TextureFile()
{
    for (auto it = std::begin(m_data); it != std::end(m_data); it++) {
        delete *it;
    }
}

TextureFile& TextureFile::operator=(const TextureFile& p_other)
{
    clear();
    m_data.resize(p_other.m_data.size());
    for (uint32 i = 0; i < p_other.m_data.size(); i++) {
        m_data[i] = new TextureData(*p_other.m_data[i]);
    }
    return *this;
}

bool TextureFile::load(const std::string& p_filename)
{
    std::ifstream input(p_filename, std::ios::in | std::ios::binary);

    input.seekg(0, std::ios::end);
    auto size = static_cast<uint32>(input.tellg());
    input.seekg(0, std::ios::beg);

    std::vector<byte> buffer(size);
    input.read(reinterpret_cast<char*>(buffer.data()), size);
    input.close();

    return assign(buffer.data(), buffer.size());
}

bool TextureFile::assign(const byte* p_data, uint32 p_size)
{
    if (p_size < 12) { return false; }
    clear();

    auto format = *reinterpret_cast<const uint32*>(p_data + 4);
    auto width  = *reinterpret_cast<const uint16*>(p_data + 8);
    auto height = *reinterpret_cast<const uint16*>(p_data + 10);

    auto pos = p_data + 12;
    auto end = p_data + p_size;

    while (pos < end) {
        auto size = *reinterpret_cast<const uint32*>(pos);
        m_data.push_back(new TextureData(width, height, format, pos, size));
        pos      += size;
        width   >>= 1;
        height  >>= 1;
    }
}

void TextureFile::clear()
{
    for (auto it = std::begin(m_data); it != std::end(m_data); it++) {
        delete *it;
    }
    m_data.clear();
}

uint16 TextureFile::width() const
{
    if (m_data.size() == 0) { return 0; }
    return m_data[0]->width();
}

uint16 TextureFile::height() const
{
    if (m_data.size() == 0) { return 0; } 
    m_data[0]->height();
}

uint32 TextureFile::format() const
{
    if (m_data.size() == 0) { return 0; } 
    m_data[0]->format();
}

uint32 TextureFile::mipMapCount() const
{
    return m_data.size();
}

const ITextureData& TextureFile::mipMapLevel(uint32 p_level) const
{
    if (p_level >= m_data.size()) { throw std::out_of_range("The given index is too large."); }
    return *m_data[p_level];
}

}; // namespace gw2f
