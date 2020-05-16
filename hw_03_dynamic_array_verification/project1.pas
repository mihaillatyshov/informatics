program project1;

type
  TArray = array of Integer;

function FindNE(const Arr : TArray; const val : Integer; s : Integer; e : Integer) : Integer;
var CV : Integer;
begin
  CV := (s + e) div 2;

  if ((s = e) or (Arr[CV] = val)) then
    Exit(CV);

  if (Arr[CV] > val) then
    e := CV
  else
    s := CV;

  Exit(FindNE(Arr, val, s, e));
end;

function FindOne(const Arr1 : TArray; const Arr2 : TArray; const K : Integer) : Integer;
begin
  if (K <= Length(Arr1)) then
    Exit(Arr1[K - 1])
  else
    Exit(Arr2[K - Length(Arr1) - 1]);
end;

function FindTwo(const Arr1 : TArray; const Arr2 : TArray; const K : Integer) : Integer;
var
  fs, fe : Integer;
  Eq : Integer;
  i, id : Integer;
  LastVal, RidM, RidN, ValId : Integer;
begin
  fs := FindNE(Arr1, Arr2[0], 0, Length(Arr1) - 1);
  if (Arr1[fs] > Arr2[0]) then
    fs -= 1;

  if ((K - 1) <= fs) then
    Exit(K - 1);

  if Arr1[fs] <= Arr2[0] then
  begin
    LastVal := Arr1[fs];
    RidM := fs + 1;
    RidN := 0;
  end
  else
  begin
    LastVal := Arr2[0];
    RidM := fs;
    RidN := 1;
  end;
  ValId := fs + 1;

  while ValId < K do
  begin
    if RidM = Length(Arr1) then
    begin
      if Arr2[RidN] > LastVal then
        ValId += 1;
      LastVal := Arr2[RidN];
      RidN += 1;
      continue;
    end;

    if RidN = Length(Arr2) then
    begin
      if Arr1[RidM] > LastVal then
        ValId += 1;
      LastVal := Arr1[RidM];
      RidM += 1;
      continue;
    end;

    if (Arr1[RidM] <= Arr2[RidN]) then
    begin
      if Arr1[RidM] > LastVal then
        ValId += 1;
      LastVal := Arr1[RidM];
      RidM += 1;
    end
    else
    begin
      if Arr2[RidN] > LastVal then
        ValId += 1;
      LastVal := Arr2[RidN];
      RidN += 1;
    end;
  end;

  Exit(LastVal);

  {
  fe := FindNE(Arr2, Arr1[Length(Arr1) - 1], 0, Length(Arr2) - 1);
  if (Arr2[fe] < Arr1[Length(Arr1) - 1]) then
    fe += 1;

  Eq := 0;
  for i := fs to (Length(Arr1) - 1) do
  begin
    id := FindNE(Arr2, Arr1[i], 0, fe);
    if (Arr1[i] = Arr2[id]) then
      Eq += 1;
  end;
  }



end;

function FindThr(const ArrM : TArray; const ArrN : TArray; const K : Integer): Integer;   
var
  LastVal, RidM, RidN, ValId, i : Integer;
begin
  if ArrM[0] <= ArrN[0] then
  begin
    LastVal := ArrM[0];
    RidM := 1;
    RidN := 0;
  end
  else
  begin
    LastVal := ArrN[0];
    RidM := 0;
    RidN := 1;
  end;
  ValId := 1;

  while ValId < K do
  begin
    if RidM = Length(ArrM) then
    begin
      if ArrN[RidN] > LastVal then
        ValId += 1;
      LastVal := ArrN[RidN];
      RidN += 1;
      continue;
    end;

    if RidN = Length(ArrN) then
    begin
      if ArrM[RidM] > LastVal then
        ValId += 1;
      LastVal := ArrM[RidM];
      RidM += 1;
      continue;
    end;

    if (ArrM[RidM] <= ArrN[RidN]) then
    begin
      if ArrM[RidM] > LastVal then
        ValId += 1;
      LastVal := ArrM[RidM];
      RidM += 1;
    end
    else
    begin
      if ArrN[RidN] > LastVal then
        ValId += 1;
      LastVal := ArrN[RidN];
      RidN += 1;
    end;
  end;
end;

var
  M, N, K : Integer;
  ArrM, ArrN : TArray;
  RidM, RidN, ValId : Integer;
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
  if (ArrM[Length(ArrM) - 1] < ArrN[0]) then
    LastVal := FindOne(ArrM, ArrN, K)
  else if (ArrN[Length(ArrN) - 1] < ArrM[0]) then
    LastVal := FindOne(ArrN, ArrM, K)
  else if ((ArrM[0] >= ArrN[0]) and (ArrM[Length(ArrM) - 1] <= ArrN[Length(ArrN) - 1])) then
    LastVal := FindTwo(ArrM, ArrN, K)
  else if ((ArrN[0] >= ArrM[0]) and (ArrN[Length(ArrN) - 1] <= ArrM[Length(ArrM) - 1])) then
    LastVal := FindTwo(ArrN, ArrM, K)
  else if ((ArrM[0] <= ArrN[Length(ArrN) - 1]) and (ArrM[Length(ArrM) - 1] >= ArrN[Length(ArrN) - 1])) then
    LastVal := FindThr(ArrM, ArrN, K)
  else if ((ArrN[0] <= ArrM[Length(ArrM) - 1]) and (ArrN[Length(ArrN) - 1] >= ArrM[Length(ArrM) - 1])) then
    LastVal := FindThr(ArrN, ArrM, K);


  WriteLn('Found value: ', LastVal);
  ReadLn();
end.

