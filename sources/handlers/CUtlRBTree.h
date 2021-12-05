#pragma once
#include "CUtlMemory.h"

template <typename T>
struct CUtlMemory;

template <typename T, typename U>
struct CUtlRBTree
{
    using LessFunc_t = bool(const T *, const T *);

    enum class NodeColor_t
    {
        RED = 0,
        BLACK = 1,
    };
    
    struct Links_t
    {
        U m_Left;
        U m_Right;
        U m_Parent;
        U m_Tag;
    };

    struct Node_t : public Links_t
    {
        T m_Data;
    };

    LessFunc_t m_LessFunc;
    CUtlMemory<Node_t> m_Elements;
    U m_Root;
    U m_NumElements;
    U m_FirstFree;
    U m_TotalElements;
};