<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1538675159476" ID="ID_1984811301" MODIFIED="1555441858659" TEXT="Zumo Programmierung">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">messen </font>
    </p>
    <p>
      <font size="4">entscheiden </font>
    </p>
    <ul>
      <li>
        <font size="4">frei = 0 = beschleunigen bis volle Fahrt</font>
      </li>
      <li>
        <font size="4">aufkommendes Hindernis = 1 - 5 = Fahrgeschwindigkeit reduzieren</font>
      </li>
      <li>
        <font size="4">Hindernis = 6 = wenden</font>
      </li>
      <li>
        <font size="4">einseitiges Hindernis = </font><font size="4" face="Cambria">&#8710;1 = ausweichen</font>
      </li>
      <li>
        <font size="4">einseitiges Hindernis = </font><font size="4" face="Cambria">&#8710;2 = ignorieren</font>
      </li>
    </ul>
    <p>
      <font size="4">ansteuern </font>
    </p>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="12"/>
<node CREATED="1539195597155" FOLDED="true" ID="ID_1394309608" MODIFIED="1555440354851" POSITION="right" TEXT="Infos">
<font NAME="Cambria" SIZE="12"/>
<icon BUILTIN="button_ok"/>
<node CREATED="1539195605739" ID="ID_819545712" MODIFIED="1555399600832" TEXT="32U4 = Micro (= Leonardo)">
<font NAME="Cambria" SIZE="14"/>
</node>
<node CREATED="1539196101019" ID="ID_910783163" MODIFIED="1555399600831" TEXT="Motor = 410 RPM = 65 cm/s">
<font NAME="Cambria" SIZE="14"/>
</node>
<node CREATED="1539197559942" ID="ID_310958718" MODIFIED="1555399600821" TEXT="Encoderimpulse/Umdrehung = 75.81 &#xd7; 12 &#x2248; 909.7 CPR">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      To reduce the required number of interrupt pins, the Zumo 32U4 main board XORs together both channels of each encoder and connects the resulting signal to an interrupt pin, while channel B of each encoder is connected to a non-interrupt pin:
    </p>
    <p>
      &#8226; Digital pin 7, or PE6, reads the right encoder XORed signal using external interrupt INT6.
    </p>
    <p>
      &#8226; Digital pin 8, or PB4, reads the left encoder XORed signal using pin change interrupt PCINT4.
    </p>
    <p>
      &#8226; Digital pin 23 (analog pin 5), or PF0, reads the right encoder channel B.
    </p>
    <p>
      &#8226; Pin PE2 reads the left encoder channel B.
    </p>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="14"/>
</node>
<node CREATED="1545406625155" ID="ID_389826269" MODIFIED="1555399600817" TEXT="ProximitySensors = 0 (!!!) - 6">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      6 ~ 30cm&#160;Abstand
    </p>
    <p>
      5 ~ 55cm Abstand
    </p>
    <p>
      4 ~ 77cm Abstand
    </p>
    <p>
      3 ~ 118cm Abstand
    </p>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="14"/>
</node>
<node CREATED="1545406687958" ID="ID_844648342" MODIFIED="1555399600806" TEXT="Motors = 0 - 400 (2 Byte!!!)">
<font NAME="Cambria" SIZE="14"/>
</node>
<node CREATED="1546369572644" ID="ID_1017890351" MODIFIED="1555399600785" TEXT="Formel f&#xfc;r Abstand und Geschwindigkeit">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      https://rechneronline.de/funktionsgraphen/
    </p>
    <p>
      
    </p>
    <p>
      http://www.nachlernmaterial.de/wie-kann-ich-aus-einem-graphen-die-funktionsgleichung-bestimmen-und-umgekehrt/
    </p>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="14"/>
</node>
</node>
<node CREATED="1538675191977" FOLDED="true" ID="ID_187336572" MODIFIED="1555400004395" POSITION="right" TEXT="Welche Programmierumgebung benutzen?">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <ol>
      <li>
        <font face="Courier New" size="4">Als erstes programmiere ich mit dem Micro-PlugIn in AtmelStudio, da ich dann erst einmal funktionierende Bibliotheken nutzen kann.</font>
      </li>
    </ol>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="12"/>
<icon BUILTIN="button_ok"/>
<node CREATED="1538675256437" FOLDED="true" ID="ID_1244246604" MODIFIED="1555399845140" TEXT="Arduino IDE">
<icon BUILTIN="stop"/>
<node CREATED="1538675410226" ID="ID_1322557574" MODIFIED="1538678791967" STYLE="fork" TEXT="F&#xfc;r">
<node CREATED="1538677713704" ID="ID_176583447" MODIFIED="1538678787630">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      einfach, da libs von Pololu vorhanden
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538675413979" ID="ID_1490061540" MODIFIED="1538678155132" TEXT="Wider">
<node CREATED="1538677768994" ID="ID_1636793037" MODIFIED="1538679711948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      keine native &quot;event driven hierachical state machine&quot;
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678173620" ID="ID_785810533" MODIFIED="1538678192340" TEXT="eingeschr&#xe4;nkter Komfort"/>
</node>
</node>
<node CREATED="1538675285033" FOLDED="true" ID="ID_838973498" MODIFIED="1555399866358" TEXT="Atmel  oder Visual Studio">
<icon BUILTIN="prepare"/>
<node CREATED="1538675449424" FOLDED="true" ID="ID_1000373760" MODIFIED="1555399846901" TEXT="mit Micro">
<icon BUILTIN="button_ok"/>
<node CREATED="1538675422694" ID="ID_652831508" MODIFIED="1538764044396" TEXT="F&#xfc;r">
<node CREATED="1538677859731" ID="ID_1347018295" MODIFIED="1538677885180">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      wie Arduino IDE
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538677876225" ID="ID_762566338" MODIFIED="1538677890101">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      komfortabler, als die pure Arduino IDE
    </p>
  </body>
</html></richcontent>
<node CREATED="1538678037981" ID="ID_345883957" MODIFIED="1538678044948">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Programmiertools
    </p>
  </body>
</html></richcontent>
<node CREATED="1538678072640" ID="ID_1356566462" MODIFIED="1538678078642">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Autoversvollst&#228;ndigung
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678097907" ID="ID_1240111497" MODIFIED="1538678103947">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Suchen und Ersetzen
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538678131499" ID="ID_1358661549" MODIFIED="1538678131499">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Beobachtungstools
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1538675425934" ID="ID_855859390" MODIFIED="1538678232984" TEXT="Wider">
<node CREATED="1538677768994" ID="ID_1702309130" MODIFIED="1538679727485">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      keine native &quot;event driven hierachical state machine&quot;
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
<node CREATED="1538675486948" ID="ID_1103138290" MODIFIED="1555399811003" TEXT="pur C">
<node CREATED="1538675422694" ID="ID_649874210" MODIFIED="1538764007435" TEXT="F&#xfc;r">
<node CREATED="1538678266895" ID="ID_1264455769" MODIFIED="1538678274322">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      sparsamerer Code
    </p>
  </body>
</html></richcontent>
<node CREATED="1538678297575" ID="ID_1579550195" MODIFIED="1538678349746">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      es passt mehr&#160;in den Flash und/oder das EEPROM
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538678369735" ID="ID_1754928512" MODIFIED="1538678377661">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      bessere Kontrolle und Fehlersuche
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678394233" ID="ID_1891795628" MODIFIED="1538678402681">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      h&#246;herer Lerneffekt
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538675425934" ID="ID_671601489" MODIFIED="1538682443149" TEXT="Wider">
<node CREATED="1538678443254" ID="ID_724000357" MODIFIED="1538678448591">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      langwierig
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678472062" MODIFIED="1538678472062">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      hohe Nervenbelastung
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678482874" MODIFIED="1538678482874">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      M&#246;glichkeit des Scheiterns
    </p>
  </body>
</html></richcontent>
</node>
</node>
</node>
</node>
<node CREATED="1538675201015" FOLDED="true" ID="ID_198271477" MODIFIED="1555400002905" TEXT="QM/QPN">
<icon BUILTIN="go"/>
<node CREATED="1538675393608" FOLDED="true" ID="ID_1405778009" MODIFIED="1555399944640" TEXT="F&#xfc;r">
<icon BUILTIN="button_ok"/>
<node CREATED="1538678508339" ID="ID_1673405776" MODIFIED="1538678508339">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      event driven und hierachical
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678517544" ID="ID_1622896599" MODIFIED="1538678517544">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      kombiniertes grafisches Tool mit editierbarem Code
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678527774" ID="ID_1142679922" MODIFIED="1538678527774">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Vertiefung meines Wissens im Umgang mit QP/QM
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538675398387" FOLDED="true" ID="ID_229742051" MODIFIED="1555399983294" TEXT="Wider">
<node CREATED="1539524012456" ID="ID_925637323" MODIFIED="1555399940404" TEXT="L&#xf6;sung">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <ol>
      <li>
        In QM designen und programmieren und .ino Datei generieren
      </li>
      <li>
        mit Arduino IDE builden und uploaden
      </li>
      <li>
        In Arduino IDE -&gt; Optionen -&gt; &quot;externer Editor&quot; einstellen
      </li>
    </ol>
  </body>
</html></richcontent>
<icon BUILTIN="idea"/>
<icon BUILTIN="ksmiletris"/>
</node>
<node CREATED="1538678561051" ID="ID_1252283950" MODIFIED="1555399952127">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      schwierige Adaption an den Zumo Chip
    </p>
  </body>
</html></richcontent>
<node CREATED="1538678597864" ID="ID_1266363661" MODIFIED="1538678597864">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      BSP
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1538678614211" ID="ID_939651571" MODIFIED="1538678614211">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      header files
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1538678574749" ID="ID_387390444" MODIFIED="1538678574749">
<richcontent TYPE="NODE"><html>
  <head>
    
  </head>
  <body>
    <p>
      h&#246;chstwahrscheinlich m&#252;ssen alle Zumo Bibliotheken angepasst werden oder komplett eigene geschrieben
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1539274430639" ID="ID_580818972" MODIFIED="1555399876025" TEXT="&#xdc;berlegungen">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      ALT: Da neue Compiler Probleme mit meiner ehemaligen Micro Umsetzung auftraten, ist es vielleicht ratsam, meine urspr&#252;nglichen &#196;nderungen zu verwerfen und neu anzufangen.
    </p>
    <p>
      Und sich dann vielleicht an Pololu zu wenden.
    </p>
    <p>
      
    </p>
    <p>
      NEU: siehe und studiere Umsetzung von Nagarkar
    </p>
  </body>
</html></richcontent>
<node CREATED="1539447950794" ID="ID_913780115" LINK="https://github.com/nagarkar/pololuzumo32u4" MODIFIED="1539448012023" TEXT="Nagarkar&apos;s Umsetzung"/>
</node>
</node>
</node>
<node CREATED="1539194358878" ID="ID_188788871" MODIFIED="1555399600835" POSITION="right" TEXT="Fragen">
<font NAME="Cambria" SIZE="12"/>
<node CREATED="1541876563589" ID="ID_668761038" MODIFIED="1555399600835" TEXT="2 Parameter &#xfc;bergeben">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      F&#252;r das Fahren brauche ich zwei Parameter, da ich zwei Motoren ansteuern muss.
    </p>
    <p>
      Kann ich an ein XYZ_SIG, zwei Parameter &#252;bergeben? Irgendwie scheint Miro das ja auch im game zu machen (Parameter x, y)!?
    </p>
    <p>
      
    </p>
    <p>
      Oder definiere ich ein 2-Byte-Parameter und lege einen Wert ins LSB und einen ins MSB?
    </p>
    <p>
      
    </p>
    <p>
      Irgendwie so:
    </p>
    <b>uint8_t x = (uint8_t)Q_PAR(me); </b>

    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <b>uint8_t y = (uint8_t)(Q_PAR(me) &gt;&gt; 8); </b>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      uint8_t bmp = (uint8_t)(Q_PAR(me) &gt;&gt; 16);
    </p>
    <p>
      
    </p>
    <p>
      Wo setze ich Q_PARAM_SIZE?
    </p>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="14"/>
</node>
</node>
<node CREATED="1538840348728" FOLDED="true" ID="ID_365015684" MODIFIED="1555399600783" POSITION="right" TEXT="Welches Designtool benutzen?">
<font NAME="Cambria" SIZE="12"/>
<icon BUILTIN="button_ok"/>
<node CREATED="1541876529287" ID="ID_25110167" MODIFIED="1541876533560" TEXT="adoc"/>
</node>
<node CREATED="1538840427200" ID="ID_1276132013" MODIFIED="1555399600781" POSITION="left" TEXT="Was soll der Zumo machen?">
<font NAME="Cambria" SIZE="12"/>
<node CREATED="1539108920688" FOLDED="true" ID="ID_475536693" MODIFIED="1555399722771" TEXT="Teilaufgaben">
<font NAME="Cambria" SIZE="12"/>
<node CREATED="1539108937358" ID="ID_137728993" MODIFIED="1555399697542" TEXT="Motoren ansteuern">
<icon BUILTIN="button_ok"/>
<node CREATED="1539108974217" ID="ID_46398462" MODIFIED="1555305562382" TEXT="Gleichm&#xe4;&#xdf;igkeit synchronisieren">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Beide Encoder mitz&#228;hlen und bei Differenz den entsprechenden Motor beschleunigen, bzw. verz&#246;gern
    </p>
    <p>
      
    </p>
    <p>
      int16_t getCountsAndResetLeft();
    </p>
    <p>
      int16_t getCountsAndResetRight();
    </p>
  </body>
</html></richcontent>
</node>
</node>
<node CREATED="1539109191580" ID="ID_596105360" MODIFIED="1555399708182" TEXT="Frontsensoren abtasten">
<icon BUILTIN="button_ok"/>
</node>
<node CREATED="1548267814460" ID="ID_922834610" MODIFIED="1555399438409" TEXT="Kollision abtasten">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      the program reads the x and y components of acceleration (ignoring z), and detets a&#160;contact when the magnitude of the 3-period average of the x-y vector exceeds an empirically&#160;determined XY_ACCELERATION_THRESHOLD
    </p>
    <p>
      
    </p>
    <p>
      // check for contact, but ignore readings immediately after turning or losing contact
    </p>
    <p>
      bool check_for_contact()
    </p>
    <p>
      {
    </p>
    <p>
      &#160;&#160;static long threshold_squared = (long) XY_ACCELERATION_THRESHOLD * (long) XY_ACCELERATION_THRESHOLD;
    </p>
    <p>
      &#160;&#160;return (lsm303.ss_xy_avg() &gt;&#160;&#160;threshold_squared) &amp;&amp; \
    </p>
    <p>
      &#160;&#160;&#160;&#160;(loop_start_time - last_turn_time &gt; MIN_DELAY_AFTER_TURN) &amp;&amp; \
    </p>
    <p>
      &#160;&#160;&#160;&#160;(loop_start_time - contact_made_time &gt; MIN_DELAY_BETWEEN_CONTACTS);
    </p>
    <p>
      }
    </p>
  </body>
</html></richcontent>
<font NAME="Courier New" SIZE="12"/>
</node>
<node CREATED="1539109206683" ID="ID_396289365" MODIFIED="1555305608137" TEXT="Seitensensoren abtasten">
<font NAME="Courier New" SIZE="12"/>
</node>
<node CREATED="1539109250003" ID="ID_335363733" MODIFIED="1555305562405" TEXT="Start-Taste">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Offenbar muss ich eine timeout-Schleife machen und dann immer wieder den Button abfragen &lt;- Ja
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
</node>
<node CREATED="1539109306984" ID="ID_1990753561" MODIFIED="1555305562415" TEXT="Status LED">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      gr&#252;n = okay
    </p>
    <p>
      gelb = suche
    </p>
    <p>
      rot = gebe auf
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1539527183106" ID="ID_1323765566" MODIFIED="1555305562425" TEXT="timetick generieren">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Der timetick ist stabil. Ich bin mir nur noch nicht &#252;ber die korrekte Zeitdauer im Klaren.
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="help"/>
</node>
</node>
<node CREATED="1546970408663" ID="ID_1980648924" MODIFIED="1555399600778" TEXT="Algorithmus">
<arrowlink DESTINATION="ID_1980648924" ENDARROW="Default" ENDINCLINATION="0;0;" ID="Arrow_ID_1184872118" STARTARROW="None" STARTINCLINATION="0;0;"/>
<linktarget COLOR="#b0b0b0" DESTINATION="ID_1980648924" ENDARROW="Default" ENDINCLINATION="0;0;" ID="Arrow_ID_1184872118" SOURCE="ID_1980648924" STARTARROW="None" STARTINCLINATION="0;0;"/>
<font NAME="Cambria" SIZE="12"/>
<node CREATED="1555251101247" ID="ID_978425654" MODIFIED="1555440788763" TEXT="Abstand messen, entscheiden, ansteuern">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font face="Courier New" size="4">Problem: Die beiden Abstandssensoren sehen zu sehr das selbe, daher ist der Unterscheidungswert zu gering (bei einem Range von 0 - 6). </font>
    </p>
    <p>
      <font face="Courier New" size="4">Die abstandsgef&#252;hrte Geschwindigkeit sollte nicht bis auf 0 runtergefahren werden, um eine Kollision festzustellen. Z.B., wenn der Zumo sich festf&#228;hrt, weil der Totbereich der Sensoren erreicht ist. </font>
    </p>
    <p>
      
    </p>
    <p>
      <font face="Courier New" size="4">Situation erkennen und Aktion entscheiden: </font>
    </p>
    <ol>
      <li>
        <font face="Courier New" size="4">&#160;l &amp;&amp; r =&lt; 4 : &quot;fahre geradeaus&quot; </font>
      </li>
      <li>
        <font face="Courier New" size="4">&#160;Differenz zwischen abs(l - r) &gt;= 2 : &quot;ignoriere, da Hindernis parallel verl&#228;uft&quot; </font>
      </li>
      <li>
        <font face="Courier New" size="4">&#160;l = 5 &amp;&amp; r = 4 : &quot;biege rechts ab&quot; &amp;&amp; &quot;merke rechts&quot; || l = 4 &amp;&amp; r = 5&#160;: &quot;biege links ab&quot; &amp;&amp; &quot;merke links&quot; </font>
      </li>
      <li>
        <font face="Courier New" size="4">&#160;l || r = 6 : &quot;wende unter Ber&#252;cksichtigung des gemerkten (links/rechts)&quot; </font>
      </li>
    </ol>
    <p>
      
    </p>
    <p>
      <font face="Courier New" size="4">Aktion: </font>
    </p>
    <ol>
      <li>
        <font face="Courier New" size="4">&#160;&quot;fahre geradeaus&quot; : beschleunigen und abstandsregeln</font>
      </li>
      <li>
        &#160;
      </li>
      <li>
        <font face="Courier New" size="4">&#160;&quot;biege ab&quot; &amp;&amp; &quot;merke&quot; : 3. Formel f&#252;r bremsende Seite benutzen und merken</font>
      </li>
      <li>
        &#160;
      </li>
    </ol>
  </body>
</html></richcontent>
<font NAME="Cambria" SIZE="12"/>
</node>
<node CREATED="1555251160655" ID="ID_1200783107" MODIFIED="1555399600749" TEXT="Kontakterkennung">
<font NAME="Cambria" SIZE="12"/>
</node>
</node>
</node>
</node>
</map>
