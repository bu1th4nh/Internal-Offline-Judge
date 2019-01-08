

            //------------------Pham Ba Thai------------------//


{$MODE OBJFPC}
{$I-,Q-,B-,R-}
{$InLine On}


Program C11SEQ;


Const
   InputFile ='TSEQ.INP';
   OutputFile='TSEQ.OUT';
   nMax=100002;


Type
   ll=LongInt;


Var
   G                                    : Array [0..nMax] of ll;
   S,Cs                                 : Array [0..nMax] of Int64;
   m,n,i,j,tmp                          : ll;
   Res,pivot,L,R                        : Int64;


Procedure EnterData;
Begin
   Assign(InPut,InputFile);
   Reset(InPut);
         ReadLn(L,R,n);
         Inc(n);
         S[1]:=0;
         Cs[1]:=1;
         For i:=2 to n do
            begin
               Read(j);
               S[i]:=Int64(i-2)*j+S[i-1];
               Cs[i]:=i;
            end;
   Close(InPut);
End;


Procedure Qsort(L,H: ll); {Samll -> Big}
Var
   i,j: ll;
Begin
   if L>=H then exit;
   i:=L; j:=H;
   Pivot:=S[Cs[L+RanDom(H-L+1)]];
   Repeat
      While S[Cs[i]]<Pivot do inc(i);
      While S[Cs[j]]>Pivot do dec(j);
      If i<=j then
         begin
            if i<j then
               begin
                  tmp:=Cs[i];
                  Cs[i]:=Cs[j];
                  Cs[j]:=tmp;
               end;
            inc(i); dec(j);
         end;
   Until i>j;
   Qsort(L,j); Qsort(i,H);
End;


Procedure Init;
Begin
   RanDomize;
   Qsort(1,n);
   m:=0;
   S[Cs[n+1]]:=High(Int64);
   For i:=1 to n do
      If S[Cs[i]]<>S[Cs[i+1]] then
         begin
            Inc(m);
            Cs[m]:=S[Cs[i]];
         end;
End;


Function Find(x: Int64): ll;
Var
   d,c,g: ll;
Begin
   d:=1;
   c:=m;
   Find:=0;
   Repeat
      g:=(d+c) Shr 1;
      If Cs[g]<=x then
         begin
            Find:=g;
            d:=g+1;
         end
      else c:=g-1;
   Until d>c;
End;


Procedure UpDate(x: ll);   InLine;
Begin
   Repeat
      Inc(G[x]);
      x:=x+(x and -x);
   Until x>m;
End;


Function Show(x: ll): ll;  InLine;
Begin
   Show:=0;
   WHile x<>0 do
      begin
         Inc(Show,G[x]);
         x:=x and (x-1);
      end;
End;


Procedure Process;
Begin
   Init;
   UpDate(Find(0));
   For i:=2 to n do
      begin
         Res:=Res+Show(Find(S[i]-L))-Show(Find(S[i]-R-1));
         UpDate(Find(S[i]));
      end;
End;


Procedure PrintResult;
Begin
   Assign(OutPut,OutputFile);
   Rewrite(OutPut);
   Write(Res);
   Close(OutPut);
End;


BEGIN
   EnterData;
   Process;
   PrintResult;
END.

         //------------------Thu ba ngay 13/8/2013----------------//

