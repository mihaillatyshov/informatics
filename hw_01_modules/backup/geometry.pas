unit Geometry;


interface

type
  Point = record
    x : Real;
    y : Real;
  end;

  Line = record
    A : Point;
    B : Point;
  end;

  Triangle = record
    A : Point;
    B : Point;
    C : Point;
  end;

function CreatePoint(const x : Real; const y : Real) : Point;
function CreateTriangle(const A : Point; const B : Point; const C : Point) : Triangle;
function CreateLine(const A : Point; const B : Point) : Line;

function GetDistance(const l : Point; const r : Point) : Real;
function GetTrPer(const T : Triangle) : Real;
function GetTrSq(const T : Triangle) : Real;

function Dot(const l : Point; const r : Point) : Real;
function Cross(const v : Point) : Point;
function Length(const v : Point) : Real;
function Normalize(const v : Point) : Point;

function IntersectionTest(const P1 : Point; const P2 : Point; const L : Line) : Boolean;
function IntersectionTest(const T : Triangle; const L : Line) : Boolean;

implementation

function CreatePoint(const x : Real; const y : Real) : Point;
begin
  CreatePoint.x := x;
  CreatePoint.y := y;
end;


function GetDistance(const l : Point; const r : Point) : Real;
var vec : Point;
begin
  vec.x := l.x - r.x;
  vec.y := l.y - r.y;
  GetDistance := sqrt(vec.x * vec.x + vec.y * vec.y);
end;


function CreateTriangle(const A : Point; const B : Point; const C : Point) : Triangle;
begin
  CreateTriangle.A := A;
  CreateTriangle.B := B;
  CreateTriangle.C := C;
end;


function CreateLine(const A : Point; const B : Point) : Line;
begin
  CreateLine.A := A;
  CreateLine.B := B;
end;

procedure TrPerAndSide(const T : Triangle; out AB : Real; out BC : Real; out AC : Real; out Per : Real);
begin
  AB := GetDistance(T.A, T.B);
  BC := GetDistance(T.B, T.C);
  AC := GetDistance(T.A, T.C);
  Per := GetTrPer(T);
end;


function GetTrPer(const T : Triangle) : Real;
begin
  GetTrPer := GetDistance(T.A, T.B) + GetDistance(T.B, T.C) + GetDistance(T.A, T.C);
end;


function GetTrSq(const T : Triangle) : Real;
var
  p : Real;
  AB, BC, AC : Real;
begin
  TrPerAndSide(T, AB, BC, AC, p);
  p /= 2.0;
  GetTrSq := sqrt(p * (p - AB) * (p - BC) * (p - AC));
end;


function Dot(const l : Point; const r : Point) : Real;
begin
  Dot := l.x * r.x + l.y * r.y;
end;


function Cross(const v : Point) : Point;
begin
  Cross.x := -v.y;
  Cross.y := v.x;
end;


function Length(const v : Point) : Real;
begin
  Length := sqrt(Dot(v, v));
end;


function Normalize(const v : Point) : Point;
begin
  Normalize.x := v.x / Length(v);
  Normalize.y := v.y / Length(v);
end;


function IntersectionTest(const P1 : Point; const P2 : Point; const L : Line) : Boolean;
var
  LineNormal : Point;
  DistP1 : Real;
  DistP2 : Real;
begin
  LineNormal := Normalize(Cross(CreatePoint(L.A.x - L.B.x, L.A.y - L.B.y)));

  DistP1 := Dot(LineNormal, CreatePoint(P1.x - L.A.x, P1.y - L.A.y)); 
  DistP2 := Dot(LineNormal, CreatePoint(P2.x - L.A.x, P2.y - L.A.y));

  if ((DistP1 > 0.0) and (DistP2 < 0.0)) then
    exit(true);
  if ((DistP1 < 0.0) and (DistP2 > 0.0)) then
    exit(true);

  exit(false);
end;


function IntersectionTest(const T : Triangle; const L : Line) : Boolean;
begin
  if (IntersectionTest(T.A, T.B, L)) then
    exit(true);                          
  if (IntersectionTest(T.B, T.C, L)) then
    exit(true);
  if (IntersectionTest(T.A, T.C, L)) then
    exit(true);

  exit(false);
end;


end.
