// File: pf/chunks/mapc/PackMapCubeMap.cpp

#include <gw2formats/pf/chunks/mapc/PackMapCubeMap.h>

namespace gw2f {
namespace pf {
namespace chunks {

//============================================================================/
//      PackMapCubeMapSampleV3
//============================================================================/

PackMapCubeMapSampleV3::PackMapCubeMapSampleV3()
    : envID(0)
{
}

PackMapCubeMapSampleV3::PackMapCubeMapSampleV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCubeMapSampleV3::PackMapCubeMapSampleV3(const PackMapCubeMapSampleV3& p_other)
    : position(p_other.position)
    , filenameDayDefault(p_other.filenameDayDefault)
    , filenameNightDefault(p_other.filenameNightDefault)
    , filenameDayScript(p_other.filenameDayScript)
    , filenameNightScript(p_other.filenameNightScript)
    , envID(p_other.envID)
{
}

PackMapCubeMapSampleV3& PackMapCubeMapSampleV3::operator=(const PackMapCubeMapSampleV3& p_other)
{
    position             = p_other.position;
    filenameDayDefault   = p_other.filenameDayDefault;
    filenameNightDefault = p_other.filenameNightDefault;
    filenameDayScript    = p_other.filenameDayScript;
    filenameNightScript  = p_other.filenameNightScript;
    envID                = p_other.envID;
    return *this;
}

const byte* PackMapCubeMapSampleV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, position);
    p_data = helpers::read(p_data, p_size, filenameDayDefault);
    p_data = helpers::read(p_data, p_size, filenameNightDefault);
    p_data = helpers::read(p_data, p_size, filenameDayScript);
    p_data = helpers::read(p_data, p_size, filenameNightScript);
    p_data = helpers::read(p_data, p_size, envID);
    return p_data;
}

//============================================================================/
//      PackMapCubeMapParamsV3
//============================================================================/

PackMapCubeMapParamsV3::PackMapCubeMapParamsV3()
    : modulateColor(0)
    , brightness(0)
    , contrast(0)
    , blurPasses(0)
{
}

PackMapCubeMapParamsV3::PackMapCubeMapParamsV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCubeMapParamsV3::PackMapCubeMapParamsV3(const PackMapCubeMapParamsV3& p_other)
    : modulateColor(p_other.modulateColor)
    , brightness(p_other.brightness)
    , contrast(p_other.contrast)
    , blurPasses(p_other.blurPasses)
    , envVolume(p_other.envVolume)
{
}

PackMapCubeMapParamsV3& PackMapCubeMapParamsV3::operator=(const PackMapCubeMapParamsV3& p_other)
{
    modulateColor = p_other.modulateColor;
    brightness    = p_other.brightness;
    contrast      = p_other.contrast;
    blurPasses    = p_other.blurPasses;
    envVolume     = p_other.envVolume;
    return *this;
}

const byte* PackMapCubeMapParamsV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, modulateColor);
    p_data = helpers::read(p_data, p_size, brightness);
    p_data = helpers::read(p_data, p_size, contrast);
    p_data = helpers::read(p_data, p_size, blurPasses);
    p_data = helpers::read(p_data, p_size, envVolume);
    return p_data;
}

//============================================================================/
//      PackMapCubeMapV3
//============================================================================/

PackMapCubeMapV3::PackMapCubeMapV3()
{
}

PackMapCubeMapV3::PackMapCubeMapV3(const byte* p_data, uint32 p_size, const byte** po_pointer)
{
    auto pointer = assign(p_data, p_size);
    if (po_pointer) { *po_pointer = pointer; }
}

PackMapCubeMapV3::PackMapCubeMapV3(const PackMapCubeMapV3& p_other)
    : sampleArray(p_other.sampleArray)
    , paramsArray(p_other.paramsArray)
{
}

PackMapCubeMapV3& PackMapCubeMapV3::operator=(const PackMapCubeMapV3& p_other)
{
    sampleArray = p_other.sampleArray;
    paramsArray = p_other.paramsArray;
    return *this;
}

const byte* PackMapCubeMapV3::assign(const byte* p_data, uint32 p_size)
{
    p_data = helpers::read(p_data, p_size, sampleArray);
    p_data = helpers::read(p_data, p_size, paramsArray);
    return p_data;
}

}; // namespace chunks
}; // namespace pf
}; // namespace gw2f
