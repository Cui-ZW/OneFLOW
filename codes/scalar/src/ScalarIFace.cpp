/*---------------------------------------------------------------------------*\
    OneFLOW - LargeScale Multiphysics Scientific Simulation Environment
    Copyright (C) 2017-2021 He Xin and the OneFLOW contributors.
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

#include "ScalarIFace.h"
#include "MetisGrid.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

BeginNameSpace( ONEFLOW )

ScalarIFaceIJ::ScalarIFaceIJ()
{
    ;
}

ScalarIFaceIJ::~ScalarIFaceIJ()
{
}

ScalarIFace::ScalarIFace()
{
    ;
}

ScalarIFace::~ScalarIFace()
{
}
//IFace( iZone, jZone );
//iface(2,3,4,5,6) ��Ӧ�Լ���ghostcell�ֱ�Ϊ��nCell+2��nCell+3��nCell+4��nCell+5��nCell+6��
//�����ZoneΪ2��ʵ��cell��7,8,9,10,11(�ֲ�cell id)��ȫ��idΪ��70,80,90,100,110��
//iface(10,11,12) ��Ӧ�Լ���ghostcell�ֱ�Ϊ��nCell+10��nCell+11��nCell+12����Ӧ�����ZoneΪ3��cell��31,34,47(�ֲ�cell id)��ȫ��idΪ��310,340,470��
//��ôlen��iface��1,2����=5��Ҳ����5��Ԫ�أ���ʱ����ͨ�����߶Է���á�

void ScalarIFace::GetInterface()
{
    int nNeis = data.size();
    for( int iNei = 0; iNei < nNeis; ++ iNei)
    {
        ScalarIFaceIJ & iFaceIJ = data[ iNei ];
        int iZone =  iFaceIJ.zonej;
        vector<int> & ghostCells = iFaceIJ.ghostCells;
    }
}

void ScalarIFace::CalcInterface( GridTopo * gridTopo )
{
    this->zoneid = gridTopo->zoneid;
    int nFaces = gridTopo->facetype.size();
    for ( int iFace = 0; iFace < nFaces; ++ iFace )
    {
        int facetype = gridTopo->facetype[ iFace ];
        if ( facetype == -1 )
        {
            int faceid = gridTopo->faceid[ iFace ];
            ifaces.push_back( faceid );
        }
    }
    int kkk = 1;
}

ScalarIFaces::ScalarIFaces()
{
    ;
}

ScalarIFaces::~ScalarIFaces()
{
    ;
}

void ScalarIFaces::GetInterface()
{
    int nZones = data.size();
    for( int iZone = 0; iZone < nZones; ++ iZone )
    {
        data[ iZone ].GetInterface();
    }
}

void ScalarIFaces::CalcInterface( GridTopos * gridTopos )
{
    int nZones = data.size();
    for( int iZone = 0; iZone < nZones; ++ iZone )
    {
        data[ iZone ].CalcInterface( & gridTopos->data[ iZone ] );
    }
}

EndNameSpace