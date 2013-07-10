/* 
 * INTEL CONFIDENTIAL
 * Copyright © 2011 Intel 
 * Corporation All Rights Reserved.
 * 
 * The source code contained or described herein and all documents related to
 * the source code ("Material") are owned by Intel Corporation or its suppliers
 * or licensors. Title to the Material remains with Intel Corporation or its
 * suppliers and licensors. The Material contains trade secrets and proprietary
 * and confidential information of Intel or its suppliers and licensors. The
 * Material is protected by worldwide copyright and trade secret laws and
 * treaty provisions. No part of the Material may be used, copied, reproduced,
 * modified, published, uploaded, posted, transmitted, distributed, or
 * disclosed in any way without Intel’s prior express written permission.
 * 
 * No license under any patent, copyright, trade secret or other intellectual
 * property right is granted to or conferred upon you by disclosure or delivery
 * of the Materials, either expressly, by implication, inducement, estoppel or
 * otherwise. Any license under such intellectual property rights must be
 * express and approved by Intel in writing.
 * 
 * CREATED: 2011-06-01
 * UPDATED: 2011-07-27
 */
#pragma once

#include <map>
#include <string>

#include "Element.h"

class CElementBuilder;

class CElementLibrary
{
    typedef std::map<string, const CElementBuilder*> ElementBuilderMap;
    typedef ElementBuilderMap::iterator ElementBuilderMapIterator;
    typedef ElementBuilderMap::const_iterator ElementBuilderMapConstIterator;

public:
    CElementLibrary();
    virtual ~CElementLibrary();

    /** Add a xml tag and it's corresponding builder in the library.
       *
       * @param[in] xmlTag is the tag of an xml element that can be given to the builder to
       *               create a new element.
       * @param[in] pElementBuilder is the tag associated element builder.
       */
    void addElementBuilder(const std::string& type, const CElementBuilder *pElementBuilder);
    void clean();

    // Instantiation
    CElement* createElement(const CXmlElement& xmlElement) const;

private:
    // Builder type
    virtual std::string getBuilderType(const CXmlElement& xmlElement) const;

    // Builders
    ElementBuilderMap _elementBuilderMap;
};
