#pragma once
#include "targetver.h"

#include <vld.h>

//#pragma warning(push, 3)
//#pragma warning(disable:4365 4514 4820)
//#	include <algorithm>
//#pragma warning(pop)

#pragma warning(push, 3)
#pragma warning(disable:4365 4514 4571 4625 4626 4710 4711 4774 4820 5026 5027)
#include <complex>
#pragma warning(pop)

#pragma warning(push, 3)
#pragma warning(disable: 4365 4514 4571 4625 4626 4710 4711 4774 4820 5026 5027)
#	include <iostream>
#pragma warning(pop)

#pragma warning(push, 3)
#pragma warning(disable: 4365 4571 4626 4710 4711 4774 26439 26451)
#	include <DirectXTK\Audio.h>
#pragma warning(pop)
#if min(WINVER, _WIN32_WINNT) < _WIN32_WINNT_WIN8
#	pragma comment(lib, "DirectXTKAudioDX")
#else
#	pragma comment(lib, "DirectXTKAudioWin8")
#endif

#pragma warning(push, 2)
#	include <libavutil/samplefmt.h>
#pragma warning(pop)

#pragma warning(push, 2)
#pragma warning(disable: 4365 4571 4625 4626 4710 4711 4774 4820 5026 5027 26434 26439 26495)
#	define BOOST_PYTHON_STATIC_LIB
#	define BOOST_NUMPY_STATIC_LIB
//#	include <boost/python/numpy.hpp>
#pragma warning(pop)