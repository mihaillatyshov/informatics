program project1;

Type
  IntMat = array of array of Integer;

var
  arr : IntMat;
  W, H : Integer;
  i, j, xc, yc, x, y : Integer;
  AddVal : Integer;
  IsAddDirUp : Boolean;

function IncDec() : Integer;
begin
  IncDec := AddVal;
  if AddVal = 1 then
    IsAddDirUp := true;
  if AddVal = 9 then
    IsAddDirUp := false;

  if IsAddDirUp then
    AddVal += 1
  else
    AddVal -= 1;

end;

begin
  Write('Enter W, H: ');
  ReadLn(W, H);

  SetLength(arr, H);

  for i := 0 to H - 1 do
    SetLength(arr[i], W);

  xc := W;
  yc := H - 1;
  x := 0;
  y := 0;

  AddVal := 1;

  while (xc + yc) > 0 do
  begin
    for i := 0 to xc - 1 do
    begin
      arr[y][x + i] := IncDec();
    end;
    if yc = 0 then
      break;
    xc -= 1;
    x += i;
    y += 1;

    for i := 0 to yc - 1 do
    begin
      arr[y + i][x] := IncDec();
    end;
    if xc = 0 then
      break;
    yc -= 1;
    x -= 1;
    y += i;

    for i := 0 to xc - 1 do
    begin
      arr[y][x - i] := IncDec();
    end;     
    if yc = 0 then
      break;
    xc -= 1;
    x -= i;
    y -= 1;

    for i := 0 to yc - 1 do
    begin
      arr[y - i][x] := IncDec();
    end;
    if xc = 0 then
      break;
    yc -= 1;
    x += 1;
    y -= i;

  end;


  for i := 0 to H - 1 do
  begin
    for j := 0 to W - 1 do
    begin
      Write(arr[i][j]:3);
    end;
    WriteLn();
  end;


  ReadLn();
end.

