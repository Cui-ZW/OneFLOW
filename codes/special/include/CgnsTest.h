/*---------------------------------------------------------------------------*\
    OneFLOW - LargeScale Multiphysics Scientific Simulation Environment
    Copyright (C) 2017-2020 He Xin and the OneFLOW contributors.
-------------------------------------------------------------------------------
License
    This file is part of OneFLOW.

    OneFLOW is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OneFLOW is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OneFLOW.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/


#pragma once
#include "HXDefine.h"
#include <string>
using namespace std;

BeginNameSpace( ONEFLOW )

class CgnsBase;

class CgnsTest
{
public:
    CgnsTest();
    ~CgnsTest();
public:
    string fileName;
    int index_file;
    int curr_base_id;
    int nBases;
    HXVector< CgnsBase * > baseList;
public:
    void Init();
    void Run();
    void Test();
public:
    void SetDefaultGridName();
    void ReadNondimensionalParameter();
    void WriteNondimensionalParameter();
    void WriteDescriptor();
    void ReadDescriptor();
    void ReadBaseDescriptor( int baseIndex );
    void WriteSimpleMultiBaseTest();
    void ReadSimpleMultiBaseTest();
    void TestCgnsLink();
public:
    void OpenCgnsFile( int cgnsOpenMode );
    void OpenCgnsFile( const string & fileName, int cgnsOpenMode );
    void CloseCgnsFile();
    void CloseCgnsFile( int index_file );
    string GetCgnsFileTypeName( int file_type );
    void WriteBase( const string & baseName );
    void WriteBase( const string & baseName, int celldim, int physdim );
public:
    void WriteDouble( const string & varName, const double & varValue );
    void GotoBaseBegin( int baseIndex );
public:
    void ReadEmptyCgnsFile();
    void WriteEmptyCgnsFile();

};


EndNameSpace