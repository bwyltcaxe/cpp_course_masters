#pragma once

#include <cstddef>
#include <memory>

struct impl;

struct deleter
{
  void operator()(impl *);
};

class pimpl
{
    std::unique_ptr<impl, deleter> data_;

public:
    pimpl ();
    void call ();
};

#define FPIMPL_STORAGE_SIZE 32

class fast_pimpl
{
    std::aligned_storage_t<FPIMPL_STORAGE_SIZE, alignof(std::max_align_t)> storage_;
    impl* data_;

public:
    fast_pimpl ();
    ~fast_pimpl ();

    void call ();
};

