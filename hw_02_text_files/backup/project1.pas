program project1;

type
  Data = record
    Time : Integer;
    Id : Integer;
    Enters : Integer;
    IsUpdated : Boolean;
  end;

var
  Files : array of TextFile;
  FilePath : String;
  FilesCount : Integer;
  UsersInfo : array of Data;
  EndFile : TextFile;
  IsEnd : Boolean;
  MaxId : Integer;
  i : Integer;

begin
  Write('Enter files count: ');
  ReadLn(FilesCount);

  SetLength(Files, FilesCount);
  SetLength(UsersInfo, FilesCount);
  IsEnd := false;
  for i := 0 to FilesCount - 1 do
  begin
    WriteLn('Enter FilePath: ');
    ReadLn(FilePath);
    Assign(Files[i], FilePath);
    ReSet(Files[i]);
    UsersInfo[i].IsUpdated := true;
  end;

  Assign(EndFile, 'EndFile.txt');  
  ReWrite(EndFile);

  while true do
  begin             
    IsEnd := true;
    for i := 0 to FilesCount - 1 do
    begin
      if not EOF(Files[i]) then
      begin
        if UsersInfo[i].IsUpdated then
        begin
          UsersInfo[i].IsUpdated := false;
          Read(Files[i], UsersInfo[i].Time);
          Read(Files[i], UsersInfo[i].Id);
          Read(Files[i], UsersInfo[i].Enters);
          //WriteLn(UsersInfo[i].Time, UsersInfo[i].Id, UsersInfo[i].Enters);
        end;
      end;

      if not UsersInfo[i].IsUpdated then
        IsEnd := false;

    end;

    if IsEnd then
      break;


    //Find first not updated element
    for i := 0 to FilesCount - 1 do
    begin
      if not UsersInfo[i].IsUpdated then
      begin
        MaxId := i;
        break;
      end;
    end;

    //Find Max and add
    for i := i + 1 to FilesCount - 1 do
    begin
      if (UsersInfo[i].Enters > UsersInfo[MaxId].Enters) and (not UsersInfo[i].IsUpdated) then
        MaxId := i;
    end;

    //Write  (EndFile, UsersInfo[MaxId].Time,   ' ');
    //Write  (EndFile, UsersInfo[MaxId].Id,     ' ');
    //WriteLn(EndFile, UsersInfo[MaxId].Enters, ' ');
    UsersInfo[MaxId].IsUpdated := true;
  end;

  for i := 0 to FilesCount - 1 do
    Close(Files[i]);

  Close(EndFile);

  ReadLn();
end.

