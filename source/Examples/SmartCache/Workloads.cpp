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
    for (int32_t i = 1; i < sequenceNumber; i++)
    {
        int32_t* element = smartCache.Get(i);
        if (element == nullptr)
        {
            smartCache.Push(i, i);
        }
    }

    return 1;
}

uint64_t LFUWorkload(uint64_t sequenceNumber, SmartCacheImpl<int32_t, int32_t>& smartCache)
{
    for (int32_t k = 0; k < 4; k++) {
	for (int32_t j = 0; j < 4; j++)
	{
	    for (int32_t i = 1; i < sequenceNumber/4; i++)
	    {
	        int32_t* element = smartCache.Get(i);
	        if (element == nullptr)
	        {
	            smartCache.Push(i, i);
	        }
	    }
	}
    for (int32_t i = sequenceNumber/4; i < 3*sequenceNumber/4; i++)
    {
        int32_t* element = smartCache.Get(i);
        if (element == nullptr)
        {
            smartCache.Push(i, i);
        }
        element = smartCache.Get(i - sequenceNumber/4 + 1);
        if (element == nullptr)
        {
            smartCache.Push(i - sequenceNumber/4 + 1, i - sequenceNumber/4 + 1);
        }
    }
    for (int32_t i = 1; i < sequenceNumber/4; i++)
    {
        int32_t* element = smartCache.Get(i);
        if (element == nullptr)
        {
            smartCache.Push(i, i);
        }
    }
    }
    return 1;
}
