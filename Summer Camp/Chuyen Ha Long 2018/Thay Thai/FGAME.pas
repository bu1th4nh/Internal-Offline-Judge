//-_-_-_-_-_-_-_-_-_-_-_-               PHAM BA THAI               -_-_-_-_-_-_-_-_-_-_-_-\\

//-_-_-_-_-_-_-_-_-_-_-_-                   T1k21                  -_-_-_-_-_-_-_-_-_-_-_-\\


{$MODE OBJFPC}


Program FGAME;


Const
   InputFile ='FGAME.INP';
   OutputFile='FGAME.OUT';
   nMax=1001;


Type
   ll=LongInt;


Var
   S                                    : Array [0..nMax,0..nMax] of Byte;
   T                                    : Array [0..nMax,0..2] of Boolean;
   m,n,nTest,i,j,k                      : ll;
   Res                                  : ll;


Procedure OpenFile;
Begin
   Assign(InPut,InputFile);
   Reset(InPut);
   Assign(OutPut,OutputFile);
   Rewrite(OutPut);
End;


Procedure InitProgram;
Begin

End;


Procedure EnterData;
Begin
   ReadLn(n,m);
End;


Procedure Init;
Begin
   FillChar(T,SizeOf(T),0);
   For i:=0 to m do T[i,0]:=True;
End;


Procedure Process;
Begin
   Init;
   For i:=1 to n do
      begin
         T[0,0]:=True;
         T[0,1]:=False;
         T[0,2]:=False;
         For j:=1 to m do
            begin
               Read(k);
               S[i,j]:=(k+S[i-1,j]+S[i,j-1]-S[i-1,j-1]+3) Mod 3;
               k:=S[i,j];
               If not (T[0,(k-1+3) mod 3] or T[j,(k-1+3) mod 3]) then
                  begin
                     Res:=0;
                     T[0,k]:=True;
                     T[j,k]:=True;
                  end
               else Res:=1;
            end;
      end;
End;


Procedure PrintResult;
Begin
   WriteLn(Res);
End;


Procedure CloseFile;
Begin
   Close( InPut);
   Close(OutPut);
End;


BEGIN
   OpenFile;
   InitProgram;
   For nTest:=1 to 5 do
      begin
         EnterData;
         Process;
         PrintResult;
      end;
   CloseFile;
END.

         //-_-_-_-_-_-_-_-_-_          Thu bay ngay 8/11/2014          _-_-_-_-_-_-_-_-\\
