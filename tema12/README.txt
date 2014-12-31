Övning 12 - Grafiska utvecklingsmiljöer
Linux som utvecklingsmiljö
2014-12-30
Petter Lerenius, 790703-0295

Inledning
=========
Tema 12 går ut på att lära sig använda eclipse ihop med GTK+ och OpenCV. Den är uppdelad i två delmoment, där den första delen går ut på att lägga till funtionallitet till befintlig kod, medans den andra delen går ut på att rätta en bug i befintlig kod.

För att kunna utföra uppgifterna krävs det att man installerar och konfigurerar Eclipse, GTK+ och OpenCV, och därefter sätter upp och konfigurerar projekt i Eclipse för att kunna kompilera och länka.

Den första uppgiften går ut på att lägga till zoomnings-funktionalitet till ett program som ritar upp en Mandelbrot fraktal i ett fönster. Genom att användaren klickar med vänster eller höger musknapp ska man zooma in respektive zooma ut. Dessutom ska man utreda huruvida det går att optimera koden för att få det att beräkna fraktalen snabbare.

I den andra uppgiften ska man rätta en bugg som gör att kopieringen av en bild från en buffer till en annan blir förvrängd. Uppgiften kräver dock att man kan sätta upp ett projekt som använder sig av både OpenCV och GTK i Eclipse.

Den fullständiga beskrivningen av uppgifterna finns på kurshemsidan [1].

Metod
=====
Enligt uppgiftsbeskrivningen skulle Eclipse användas som utvecklingsmiljö. Eclipse är en IDE,
integrerad utvecklingsmiljö, som underlättar mycket för en utvecklare. Eclipse hjälper till
att generera makefiler, köra kompilatorn och länkaren, kontrollera kodsyntax, m.m. i ett och
samma skal.

För att få allting att fungera bra behöver man konfigurera Eclipse att fungera ihop med de olika
biblioteken som används i uppgifterna, så som OpenCV och GTK+.

Uppgifterna har lösts på ett system som använder Ubuntu 14.10, som körs i en VirtualBox installation
på ett Windows 8.1 system.


Resultat
========
Innan jag började med uppgifterna så laddade jag ner Eclipse genom att följa instruktionerna
på hemsidan. Därefter ladded jag ner och installerade GTK+. För att se att allting fungerade
så som det var tänkt, utförde jag exemplet som fanns där med ett enkelt GTK fönster. Därefter
kände jag mig redo att påbörja temats övningsuppgifter.

Uppgift 1
För att kunna genomföra uppgift ett behövde jag ladda ner källkodsfiler från hemsidan. Dessa
importerades sedan till ett Eclipse-projekt. För att få projektet att kompilera och länka behövde
Eclipse konfigureras för att hitta GTK+ headerfilerna. För att göra detta gjordes följande steg:

1.  Packa upp de nedladdade filerna till lämplig katalog.
2.  Starta Eclipse.
3.  Skapa ett nytt C++-projekt genom att välja File->New C++ Project.
4.  I dialogrutan som kommer upp skriv in ett projektnamn, välj Executable->Empty
    Project och Linux GCC. Ändra katalog från default till den där filerna packades
    upp. Klicka på Next.
5.  Klicka på knappen "Advanced Settings" och expandera C/C++ Build, välj sedan "Build
    Variables".
6.  I drop-down-listan "Configuration", välj "All Configurations" och klicka på "Add"
    för de båda variabelnamnen enligt kurshemsidan.
     GTK+-CFLAGS, type string, `pkg-config --cflags gtk+-2.0`
     GTK+-LIBS, type string, `pkg-config --libs gtk+-2.0`
7.  Klicka sedan på C/C++ Build->Settings och markera GCC C++ Compiler.
8.  Skriv in ${GTK+-CFLAGS} mellan ${COMMAND} och ${FLAGS} i rutan Command Line Pattern.
9.  Välj nu GCC C++ Linker och skriv in ${GTK+-LIBS} sist på raden i rutan Command Line Pattern.
10. Nu fungear det att bygga och länka, men för att Eclipse ska hitta GTK+ headerfilerna krävs
    fler konfigureringar.
11. Expandera C/C++ General och välj "Paths and Symbols".
12. Välj fliken "Includes" och klicka på "Add".
13. Bocka i rutan "Add to all languages", skriv in /usr/include/gtk-2.0 och kicka Ok.
14. Klicka nu Ok för att stänga dialogrutan och slutligen Finish.

Nu har vi konfigurerat upp Eclipse projektet för att kunna använda sig av GTK+. Om amn redan
har skapat ett projekt, så går det att högerklicka på projektnamnet i Eclipse och välja "Properties".

Nu kan projektet kompilera, länka och det går att provköra. Nu är det gdags att implementera den
efterfrågade zoomfunktionen, vilket kan göras genom att en ny fraktal beräknas vid musklick. Vid
klick med vänster musknapp dubbleras skalningsfaktorn och nya värden för fraktalens centrumpunkt
beräknas. Därefter beräknas fraktalen om genom den befintlig algoritmen, men nu med nya värden.
Vid klick med höger musknapp halveras istället skalningsfaktorn, och fraktalen beräknas om igen.

Uppgiften innebar också att man skulle undersöka om det gick att optomera beräkningen av fraktalen,
för att snabba upp applikationen. Efter att ha granskat koden kom jag fram till att man skulle
kunna dela upp beräkningen i flera trådar, t.ex. 4 stycken som beräknade en fjärdedel var, men
detta skulle bara innebära en prestanda förbättring om fyra kärnor fanns tilgängliga i systemet.
Om så inte är fallet skulle det kunna leda till en prestanda försämmring. Så det här spåret genom-
fördes inte.

En annan idé som kom upp var att behålla de redan uträknade punkterna från föregående beräkning,
och bara beräkna de nya punkterna. Detta skulle dock kräva en ganska så stor omskrivning av programmet
och även denna idén skrotades.

För att minska tiden det tar att beräkna fraktalen kan istället optimeringsnivån i Eclipse höjas.
För att få kompilatorn att optimera koden och snabba upp programexekveringen kan olika optimerings-
flaggor anges. Till gcc kan växeln -O användas för att ange att man vill att kompilatorn ska försöka
optimera koden. Den lägsta nivån, som också är standardinställningen, är -O0 och den högsta -O3.
För att ställa in optimeringsnivån i Eclipse högerklickar man på projektet och väljer "Properties".
I fönstret som öppnas expanderar man "C/C++ Build" och markerar "Settings". Under fliken "Tool Settings"
expanderar man "GCC C++ Compiler" och markerar "Optimization". Till höger finns då en drop-down meny
med titeln Optimization Level. För maximal optimering väljer man där -03. Denna förändring gjorde att
applikationen körde betydligt snabbare.

För implementationsdetaljer hänvisas till den bifogade källkoden. Ändringar
har gjorts i Uppgift1-kod/main.cpp.

Uppgift 2
Att konfigurera ett projekt för OpenCV innefattar exakt samma steg som för
konfiguration av GTK+-2.0. Byt ut GTK+-FLAGS mot OPENCV-CLAGS, GTK+-LIBS mot
OPENCV-LIBS, `pkg-config --cflags gtk+-2.0` mot `pkg-config --cflags opencv`,
`pkg-config --libs gtk+-2.0` mot `pkg-config --libs opencv` och 
/usr/include/gkt-2.0 mot /usr/include/opencv i stegen ovan.

Notera att inställningar för OpenCV kan läggas till bland de redan befintliga
inställningarna och inga behöver tas bort.

Diskussion
==========

Slutord
=======

Referenser
==========
[1] linUM: Uppgift: Övning 12 Grafiska Utvecklingsmiljöer
    http://www.moodle2.tfe.umu.se/mod/assignment/view.php?id=275

[2]


[3] linUM: Inställningar och installation av GTK+ för Eclipse
    http://www.moodle2.tfe.umu.se/mod/page/view.php?id=482

[4] linUM: TIPS vid realisering av fraktaluppgift
    http://www.moodle2.tfe.umu.se/mod/page/view.php?id=9629
