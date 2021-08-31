#pragma once

template <typename T>
struct CUtlMemory
{
    T *m_pMemory;
    int m_NumAllocated;
    int m_GrowSize;
};