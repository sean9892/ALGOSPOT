def f(s):
  l=[" ","!","$","%","(",")","*"]
  r=["20","21","24","25","28","29","2a"]
  tab={"%20":" ","%21":"!","%24":"$","%25":"%","%28":"(","%29":")","%2a":"*"}
  res=""
  lp=-1
  while lp<len(s):
    ls=res
    p=[]
    pp=[]
    for x in range(len(l)):
      p.append(s[lp+1:].find("%"+r[x]))
    if p.count(-1)==len(p):break
    for x in range(len(p)):
      if p[x]!=-1:pp.append(p[x])
    if len(pp)==0:break
    mpp=min(pp)+lp+1
    res+=s[lp+1:mpp]
    res+=tab[s[mpp:mpp+3]]
    lp=mpp+2
  return res
for x in '0'*int(input()):
  print(f(input()))
