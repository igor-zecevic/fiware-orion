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
#include "gtest/gtest.h"

#include "serviceRoutines/logTreat.h"
#include "rest/RestService.h"



/* ****************************************************************************
*
* rs - 
*/
static RestService rs[] = 
{
   { "GET",    LogRequest,                            2, { "log", "verbose"                                         }, logVerboseTreat                           },
   { "PUT",    LogRequest,                            3, { "log", "verbose", "*"                                    }, logVerboseTreat                           },
   { "POST",   LogRequest,                            3, { "log", "verbose", "*"                                    }, logVerboseTreat                           },
   { "DELETE", LogRequest,                            2, { "log", "verbose"                                         }, logVerboseTreat                           },

   { "GET",    LogRequest,                            2, { "log", "traceLevel"                                      }, logTraceTreat                             },
   { "PUT",    LogRequest,                            3, { "log", "traceLevel", "*"                                 }, logTraceTreat                             },
   { "POST",   LogRequest,                            3, { "log", "traceLevel", "*"                                 }, logTraceTreat                             },
   { "DELETE", LogRequest,                            2, { "log", "traceLevel"                                      }, logTraceTreat                             },

   { "*",      LogRequest,                            2, { "log", "*"                                               }, logErrorTreat                             },
   { "*",      LogRequest,                            3, { "log", "*", "*"                                          }, logErrorTreat                             },

   { "*",      InvalidRequest,                        0, { "*", "*", "*", "*", "*", "*"                             }, badRequest                                },

   { "",       InvalidRequest,                        0, {                                                          }, NULL                                      }
};



/* ****************************************************************************
*
* get_verbose - 
*/
TEST(versionTreat, get_verbose)
{
  ConnectionInfo ci("/log/verbose",  "GET", "1.1");
  std::string out;

  out = restService(&ci, rs);
  EXPECT_STREQ("OK", out.c_str());
}



/* ****************************************************************************
*
* put_verbose - 
*/
TEST(versionTreat, put_verbose)
{
  ConnectionInfo ci("/log/verbose/3",  "PUT", "1.1");
  std::string out;

  out = restService(&ci, rs);
  EXPECT_STREQ("OK", out.c_str());
}



/* ****************************************************************************
*
* post_verbose - 
*/
TEST(versionTreat, post_verbose)
{
  ConnectionInfo ci("/log/verbose/3",  "POST", "1.1");
  std::string out;

  out = restService(&ci, rs);
  EXPECT_STREQ("OK", out.c_str());
}



/* ****************************************************************************
*
* delete_verbose - 
*/
TEST(versionTreat, delete_verbose)
{
  ConnectionInfo ci("/log/verbose",  "DELETE", "1.1");
  std::string out;

  out = restService(&ci, rs);
  EXPECT_STREQ("OK", out.c_str());
}



