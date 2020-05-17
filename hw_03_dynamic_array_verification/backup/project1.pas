program project1;

type
  TArray = array of Integer;


function FindNE(const Arr : TArray; const val : Integer; s : Integer; e : Integer) : Integer;
var
  CV, ns, ne : Integer;
begin
  CV := (s + e) div 2;

  if ((s = e) or (Arr[CV] = val)) then
    Exit(CV);

  ns := s;
  ne := e;

  if (Arr[CV] > val) then
    ne := CV
  else
    ns := CV;

  if ((ns = s) and (ne = e)) then
    Exit(CV);

  Exit(FindNE(Arr, val, ns, ne));
end;

function FindOne(const Arr1 : TArray; const Arr2 : TArray; const K : Integer) : Integer;
begin
  if (K <= Length(Arr1)) then
    Exit(Arr1[K - 1])
  else
    Exit(Arr2[K - Length(Arr1) - 1]);
end;

function FindThr(const Arr1 : TArray; const Arr2 : TArray; const K : Integer) : Integer;
var
  fs, fe : Integer;
  TotEl : Integer;
  id, Rid1, Rid2 : Integer;
  LastVal : Integer;
begin
  fs := FindNE(Arr1, Arr2[0], 0, Length(Arr1) - 1);
  while (Arr1[fs] > Arr2[0]) do
    fs -= 1;

  if ((K - 1) <= fs) then
    Exit(Arr1[K - 1]);

  fe := FindNE(Arr2, Arr1[Length(Arr1) - 1], 0, Length(Arr2) - 1);
  while (Arr2[fe] < Arr1[Length(Arr1) - 1]) do
    fe += 1;

  TotEl := Length(Arr1) - fs + fe;
          
  WriteLn('Ban: ', fs, ' ', fe, ' ', K - Length(Arr1) - 1);
  if ((K - 1) >= (fs + TotEl)) then
    Exit(Arr2[K - Length(Arr1) - 1]);

  WriteLn('Ban: ');

  // -----------

  Rid1 := fs + 1;
  Rid2 := 0;
  LastVal := Arr2[0];
  id := fs + 1;

  while (true) do
  begin
    if (Rid1 = Length(Arr1)) then
      Exit(Arr2[Rid2 + K - id - 1]);

    if (Rid2 = fe) then
      Exit(Arr1[Rid1 + K - id - 1]);

    id += 1;
    if (Arr1[Rid1] < Arr2[Rid2]) then
    begin 
      LastVal := Arr1[Rid1];
      Rid1 += 1;
    end
    else
    begin                    
      LastVal := Arr2[Rid2];
      Rid2 += 1;
    end;

    if (id = K) then
      Exit(LastVal);
  end;
end;

function FindTwo(const Arr1 : TArray; const Arr2 : TArray; const K : Integer): Integer;
var
  fs, fe : Integer;
  TotEl : Integer;
  Disp1, Disp2 : Integer;
  i, id, Rid1, Rid2 : Integer;
  LastVal : Integer;
begin
  fs := FindNE(Arr1, Arr2[0], 0, Length(Arr1) - 1);
  if (Arr1[fs] > Arr2[0]) then
    fs -= 1;

  if ((K - 1) <= fs) then
    Exit(Arr1[K - 1]);

  fe := FindNe(Arr1, Arr2[Length(Arr2) - 1], fs, Length(Arr1) - 1);
  if (Arr1[fe] < Arr2[Length(Arr2) - 1]) then
    fe += 1;

  if (K > (fe + Length(Arr2))) then
    Exit(Arr1[K - Length(Arr2) - 1]);

  // -----------

  Rid1 := fs + 1;
  Rid2 := 0;
  LastVal := Arr2[0];
  id := fs + 1;

  while (true) do
  begin
    if (Rid1 = fs) then
      Exit(Arr2[Rid2 + K - id - 1]);

    if (Rid2 = Length(Arr2)) then
      Exit(Arr1[Rid1 + K - id - 1]);

    id += 1;
    if (Arr1[Rid1] < Arr2[Rid2]) then
    begin
      LastVal := Arr1[Rid1];
      Rid1 += 1;
    end
    else
    begin
      LastVal := Arr2[Rid2];
      Rid2 += 1;
    end;

    if (id = K) then
      Exit(LastVal);
  end;
end;

var
  M, N, K : Integer;
  ArrM, ArrN : TArray;
  LastVal : Integer;
  i : Integer;

begin
  // Geting data form user
  Write('Enter first array size: ');
  ReadLn(M);
  SetLength(ArrM, M);
  Write('Enter values: ');
  for i := 0 to Length(ArrM) - 1 do
    Read(ArrM[i]);
  ReadLn();
                                    
  Write('Enter second array size: ');
  ReadLn(N);
  SetLength(ArrN, N);
  Write('Enter values: ');
  for i := 0 to Length(ArrN) - 1 do
    Read(ArrN[i]);
  ReadLn();

  Write('Enter K value: ');
  ReadLn(K);

  // Doing somthing with data...
  if (Length(ArrN) = 0) then
    LastVal := FindOne(ArrM, ArrN, K)
  else if (Length(ArrM) = 0)
  else if (ArrM[Length(ArrM) - 1] < ArrN[0]) then
    LastVal := FindOne(ArrM, ArrN, K)
  else if (ArrN[Length(ArrN) - 1] < ArrM[0]) then
    LastVal := FindOne(ArrN, ArrM, K)
  else if ((ArrM[0] >= ArrN[0]) and (ArrM[Length(ArrM) - 1] <= ArrN[Length(ArrN) - 1])) then
    LastVal := FindTwo(ArrN, ArrM, K)
  else if ((ArrN[0] >= ArrM[0]) and (ArrN[Length(ArrN) - 1] <= ArrM[Length(ArrM) - 1])) then
    LastVal := FindTwo(ArrM, ArrN, K)
  else if ((ArrM[0] <= ArrN[Length(ArrN) - 1]) and (ArrM[Length(ArrM) - 1] >= ArrN[Length(ArrN) - 1])) then
    LastVal := FindThr(ArrN, ArrM, K)
  else if ((ArrN[0] <= ArrM[Length(ArrM) - 1]) and (ArrN[Length(ArrN) - 1] >= ArrM[Length(ArrM) - 1])) then
    LastVal := FindThr(ArrM, ArrN, K);


  WriteLn('Found value: ', LastVal);
  ReadLn();
end.

