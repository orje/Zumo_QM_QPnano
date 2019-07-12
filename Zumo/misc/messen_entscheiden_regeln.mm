<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1555441858478" ID="ID_1136660202" MODIFIED="1558707435526" TEXT="messen, entscheiden, regeln">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      * Ich gehe jetzt erst einmal davon aus, das in qpn.h die Parametergr&#246;&#223;e auf 4 vordefiniert ist. Ich ben&#246;tige 2 Byte, also eine Parametergr&#246;&#223;e von 2.
    </p>
    <p>
      * B&#252;roklammer bedeutet: Abstandsmesswerte m&#252;ssen von AO ProxSens an AO Motor &#252;bergeben
    </p>
    <p>
      werden. Eine B&#252;roklammer = ein Parameter, zwei B&#252;roklammern = zwei Parameter.
    </p>
    <p>
      
    </p>
    <p>
      * Parameter zusammensetzen und wieder zerlegen:
    </p>
    <p>
      - AO ProxiSens setzt zusammen:
    </p>
    <p>
      Parameter = leftBarrier;
    </p>
    <p>
      Parameter = Parameter &lt;&lt; 8;
    </p>
    <p>
      Parameter = Parameter | rightBarrier;
    </p>
    <p>
      
    </p>
    <p>
      - AO Motor zerlegt:
    </p>
    <p>
      leftBarrier = Parameter &gt;&gt; 8;
    </p>
    <p>
      rightBarrier = Parameter &amp; 255;
    </p>
  </body>
</html></richcontent>
<node CREATED="1558632145118" ID="ID_757919703" MODIFIED="1560700831467" POSITION="right" TEXT="a &lt; -1000">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      a &lt; -1000
    </p>
    <p>
      
    </p>
    <p>
      -vierstellig(x || y)&#160;= crash
    </p>
    <p>
      Ein negativer vierstelliger Wert von X oder Y bedeutet crash
    </p>
  </body>
</html>
</richcontent>
<node CREATED="1559320993183" ID="ID_195238863" MODIFIED="1560275594949" TEXT="Kehrtwendung">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      Am besten w&#228;re eine180&#176; Drehung, da ich eh' nicht weiss, wohin.
    </p>
    <p>
      Kurz r&#252;ckw&#228;rts, dann 180&#176;.
    </p>
  </body>
</html></richcontent>
</node>
<node CREATED="1559321019356" ID="ID_1011383163" MODIFIED="1559321021926" TEXT="else">
<node CREATED="1555443774071" ID="ID_1608642089" MODIFIED="1559320949089" STYLE="fork" TEXT="s &lt; 5">
<icon BUILTIN="button_ok"/>
<node CREATED="1555442244772" ID="ID_1232303823" MODIFIED="1557073226933" TEXT="regeln">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">Speed = aR * (Barrier - d) + e; </font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
<icon BUILTIN="attach"/>
<icon BUILTIN="attach"/>
</node>
</node>
<node CREATED="1555442146122" ID="ID_285132072" MODIFIED="1559320957872" TEXT="s &gt;= 5">
<icon BUILTIN="button_ok"/>
<node CREATED="1555442258170" ID="ID_1443366646" MODIFIED="1556991395665" TEXT="wenden">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">? leftBarrier == 6 { </font>
    </p>
    <p>
      <font size="4">leftSpeed = turnSpeed; </font>
    </p>
    <p>
      <font size="4">rightSpeed = 0; </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">} </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">&#160;</font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">else { </font>
    </p>
    <font size="4">leftSpeed = 0; </font>

    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">rightSpeed = turnSpeed; </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">}&#160; </font>
    </p>
    <p>
      <font size="4">&#160;</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
<icon BUILTIN="attach"/>
</node>
</node>
</node>
</node>
</node>
</map>
