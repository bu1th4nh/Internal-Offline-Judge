uses math;
const
        fi='swindow.inp';
        fo='swindow.out';
procedure fileio;
begin
        assign(input,fi); reset(input);
        assign(output,fo); rewrite(output);
end;
var     m,n,k:longint;
        t,p:array[0..1000005] of char;
        s:array[0..2000005] of char;
        z:array[0..2000005] of longint;
        st:array[0..1000005] of longint;
procedure enter;
var     i:longint;
begin
        n:=0;
        while not eoln do
         begin
                read(t[n]);
                inc(n);
         end;
        readln;
        m:=0;
        while not eoln do
         begin
                read(p[m]);
                inc(m);
         end;
        readln;
        read(k);
        for i:=0 to m-1 do
                s[i]:=p[i];
        s[m]:='#';
        for i:=m+1 to m+n do
                s[i]:=t[i-m-1];
end;
procedure Z_func;
var     i:longint;
        dd,l,r:longint;
begin
        dd:=m+n+1;
        l:=0; r:=0;
        z[0]:=0;
        for i:=1 to dd-1 do
         begin
                if (i<=r) then
                        z[i]:=min(r-i+1,z[i-l]);
                while (i+z[i]<dd) and (s[z[i]]=s[i+z[i]]) do inc(z[i]);
                 if (i+z[i]-1>r) then
                  begin
                        l:=i; r:=i+z[i]-1;
                  end;
        end;
end;
procedure solve;
var     i,top,vt,res:longint;
begin
        top:=0;
        res:=0;
        for i:=m+1 to m+n do
         if z[i]=m then
          begin
                inc(top);
                st[top]:=i-m-1;
          end;
        vt:=1;
        if top<>0 then
        for i:=0 to n-k do
        begin
         if st[vt]<i then
          begin
                inc(vt);
                if vt>top then break;
          end;
         if (st[vt]>=i) and (st[vt]+m-1<=i+k-1) then inc(res);
        end;
        writeln(Res);
end;
begin
        fileio;
        enter;
        z_func;
        solve;
end.