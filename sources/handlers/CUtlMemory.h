#pragma once

template <typename T>
struct CUtlMemory
{
    T *m_pMemory = nullptr;
    int m_NumAllocated = 0;
    int m_GrowSize = 256;

    explicit CUtlMemory(int initialSize)
    {
        if(initialSize)
            m_pMemory = new T[initialSize];
    }


};