//
// Copyright(c) 2016-2018 Gabi Melman.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//

#pragma once

//
// Include a bundled header-only copy of fmtlib or an external one.
// By default spdlog include its own copy.
//

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#pragma GCC diagnostic ignored "-Wsign-conversion"
#endif // __GNUC__ || __clang__



// fix warning C4996 under vs2015 about std::copy in fmt
#if defined(_MSC_VER) && _MSC_VER <= 1900
#pragma warning( push )
#pragma warning( disable : 4996 )
#endif 

#if !defined(SPDLOG_FMT_EXTERNAL)
#ifdef SPDLOG_HEADER_ONLY
#ifndef FMT_HEADER_ONLY
#define FMT_HEADER_ONLY
#endif
#endif
#ifndef FMT_USE_WINDOWS_H
#define FMT_USE_WINDOWS_H 0
#endif
#include "bundled/core.h"
#include "bundled/format.h"
#else // SPDLOG_FMT_EXTERNAL is defined - use external fmtlib
#include <fmt/core.h>
#include <fmt/format.h>
#endif

// pop warnings supressions
#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif

#if defined(_MSC_VER) && _MSC_VER <= 1900
#pragma warning( pop )
#endif