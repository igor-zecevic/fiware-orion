/*
*
* Copyright 2013 Telefonica Investigacion y Desarrollo, S.A.U
*
* This file is part of Orion Context Broker.
*
* Orion Context Broker is free software: you can redistribute it and/or
* modify it under the terms of the GNU Affero General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Orion Context Broker is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero
* General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with Orion Context Broker. If not, see http://www.gnu.org/licenses/.
*
* For those usages not covered by this license please contact with
* iot_support at tid dot es
*
* Author: Ken Zangelin
*/
#include "logMsg/logMsg.h"
#include "logMsg/traceLevels.h"

#include "ngsi/AttributeList.h"

#include "unittest.h"



/* ****************************************************************************
*
* ok - 
*/
TEST(AttributeList, ok)
{
  AttributeList  al;
  std::string    out;
  const char*    outfile1 = "ngsi.attributeList.ok.middle.xml";
  const char*    outfile2 = "ngsi.attributeList.ok.middle.json";
  
  utInit();

  out = al.render(XML, "");
  EXPECT_STREQ("", out.c_str());

  al.push_back("a1");
  al.push_back("a2");
  out = al.render(XML, "");
  EXPECT_EQ("OK", testDataFromFile(expectedBuf, sizeof(expectedBuf), outfile1)) << "Error getting test data from '" << outfile1 << "'";
  EXPECT_STREQ(expectedBuf, out.c_str());
  
  out = al.render(JSON, "");
  EXPECT_EQ("OK", testDataFromFile(expectedBuf, sizeof(expectedBuf), outfile2)) << "Error getting test data from '" << outfile2 << "'";
  EXPECT_STREQ(expectedBuf, out.c_str());

  al.push_back("");
  out = al.check(RegisterContext, XML, "", "", 0);
  EXPECT_STREQ("empty attribute name", out.c_str());

  utExit();
}
