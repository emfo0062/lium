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
Enligt uppgiftsbeskrivningen skulle Eclipse användas som utvecklingsmiljö. Eclipse är en IDE, integrerad utvecklingsmiljö, som underlättar mycket för en utvecklare. Eclipse hjälper till att generera makefiler, köra kompilatorn och länkaren, kontrollera kodsyntax, m.m. i ett och samma skal.

För att få allting att fungera bra behöver man konfigurera Eclipse att fungera ihop med de olika biblioteken som används i uppgifterna, så som OpenCV och GTK+.

Uppgifterna har lösts på ett system som använder Ubuntu 14.10 som körs i VirtualBox på en Windows 8.1 system.


Resultat
========

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
