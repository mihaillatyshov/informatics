program project1;

uses Geometry;

var
  Tri : Triangle;
  L : Line;

begin

  Tri := CreateTriangle(CreatePoint(0.0, 0.0), CreatePoint(2.0, 0.0), CreatePoint(2.0, 2.0));
  L := CreateLine(CreatePoint(1.0, -1.0), CreatePoint(1, -2.0));

  WriteLn('AB = ', GetDistance(Tri.A, Tri.B):0:6);
  WriteLn('BC = ', GetDistance(Tri.B, Tri.C):0:6);
  WriteLn('AC = ', GetDistance(Tri.A, Tri.C):0:6);

  WriteLn('Per = ', GetTrPer(Tri):0:6);
  WriteLn('Sqr = ', GetTrSq(Tri):0:6);

  
  WriteLn('IsIntersected = ', IntersectionTest(Tri, L));

  ReadLn();
end.
