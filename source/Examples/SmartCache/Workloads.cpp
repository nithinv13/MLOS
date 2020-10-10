//*********************************************************************
// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License. See License.txt in the project root
// for license information.
//
// @File: Workloads.cpp
//
// Purpose:
//      <description>
//
// Notes:
//      <special-instructions>
//
//*********************************************************************

#include <stdlib.h>
#include "stdafx.h"
#include "SmartCacheImpl.h"
#include "Workloads.h"

uint64_t CyclicalWorkload(uint64_t sequenceNumber, SmartCacheImpl<int32_t, int32_t>& smartCache)
{
    for (int32_t i = 1; i <= sequenceNumber; i++)
    {
        int32_t* element = smartCache.Get(i);
        if (element == nullptr)
        {
            smartCache.Push(i, i);
        }
    }

    return 1;
}

uint64_t RandomWorkload(uint64_t sequenceNumber, SmartCacheImpl<int32_t, int32_t>& smartCache)
{
    for (int32_t j = 1; j < 4; j++) {
    for (int32_t i = 1; i < sequenceNumber/3; i++)
    {
        //int32_t key = rand() % (sequenceNumber/4);
        int32_t key = i;
        int32_t* element = smartCache.Get(key);
        if (element == nullptr)
        {
            smartCache.Push(key, key);
        }
    }
    }
    for (int32_t i = sequenceNumber/3; i < sequenceNumber; i++)
    {
        //int32_t key = sequenceNumber/4 + (rand() % (3*sequenceNumber/4));
        int32_t key = i;
        int32_t* element = smartCache.Get(key);
        if (element == nullptr)
        {
            smartCache.Push(key, key);
        }
    }
    // for (int32_t i = 2*sequenceNumber/3; i < sequenceNumber; i++)
    // {
    //     //int32_t key = rand() % (sequenceNumber/4);
    //     int32_t key = i - (2*sequenceNumber/3);
    //     int32_t* element = smartCache.Get(key);
    //     if (element == nullptr)
    //     {
    //         smartCache.Push(key, key);
    //     }
    // }

    return 1;
}
