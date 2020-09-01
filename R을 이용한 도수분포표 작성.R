액셀<-read.csv("res1.csv",header=T);
x=액셀$저항;
n=length(x);
hx=hist(x,breaks=seq(min(x),max(x),by=(max(x)-min(x))/15),right=F);

xcf<-cumsum(hx$counts)
xrf<-hx$counts/n#상대도수
xrcf<-xcf/n; #상대누적도수;
xtable<-cbind(round(hx$mid,3),hx$counts,xcf,xrf,xrcf);

xclass<-paste0('[', round(hx$breaks[-length(hx$breaks)],3),',',round(hx$breaks[-1],3),')');
rownames(xtable)<-xclass;
colnames(xtable)<-c('대푯값','도수','누적도수','상대도수','상대누적도수')
xtable
