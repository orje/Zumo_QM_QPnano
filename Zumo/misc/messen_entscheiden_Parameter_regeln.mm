<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1555441858478" ID="ID_1136660202" MODIFIED="1556726557405" TEXT="messen, entscheiden, regeln">
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
<node CREATED="1555443143286" ID="ID_1820265369" MODIFIED="1555443149532" POSITION="right" TEXT="Abstand">
<node CREATED="1555442041869" ID="ID_1639016630" MODIFIED="1556996122876" TEXT="symetrisch">
<node CREATED="1555442135814" ID="ID_477876947" MODIFIED="1555874483273" TEXT="s = 0">
<icon BUILTIN="button_ok"/>
<node CREATED="1555874415402" ID="ID_791914318" MODIFIED="1556295011474" TEXT=" v &lt; e">
<icon BUILTIN="button_ok"/>
<node CREATED="1555442234138" ID="ID_1757857494" MODIFIED="1556295605426" TEXT="beschleunigen">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">Speed = Speed + 50U; </font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
</node>
</node>
</node>
<node CREATED="1555443774071" ID="ID_1608642089" MODIFIED="1556044189309" STYLE="fork" TEXT="s = 1 - 5">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">1 : 1 </font>
    </p>
    <p>
      <font size="4">2 : 2 </font>
    </p>
    <p>
      <font size="4">3 : 3 </font>
    </p>
    <p>
      <font size="4">4 : 4 </font>
    </p>
    <p>
      <font size="4">5 : 5 </font>
    </p>
  </body>
</html></richcontent>
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
</html>
</richcontent>
<icon BUILTIN="button_ok"/>
<icon BUILTIN="attach"/>
<icon BUILTIN="attach"/>
</node>
</node>
</node>
<node CREATED="1555442069002" ID="ID_330990518" MODIFIED="1556996122885" TEXT="asymetrisch">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">? leftBarrier &lt;&gt; rightBarrier</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
<node CREATED="1555442511432" ID="ID_1868867466" MODIFIED="1556897316967" STYLE="fork" TEXT="s &lt;= 5">
<icon BUILTIN="button_ok"/>
<node CREATED="1556461993232" ID="ID_316459498" MODIFIED="1556996139512" TEXT="l &gt; r">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">? leftBarrier &gt; rightBarrier</font>
    </p>
  </body>
</html></richcontent>
<node CREATED="1555442268867" ID="ID_1058036249" MODIFIED="1556597562064" TEXT="ausweichen">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <!--
        body { font-family: Cambria; font-size: 28pt }
        p { margin-top: 0 }
      -->
    

    <p>
      <font size="4">leftSpeed = aR * (rightBarrier - 1) + e; </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">rightSpeed = aA * (leftBarrier - 1) + e;</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
<icon BUILTIN="attach"/>
<icon BUILTIN="attach"/>
</node>
</node>
<node CREATED="1556462012102" ID="ID_157533692" MODIFIED="1556996140041" TEXT="r &gt; l">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">else</font>
    </p>
  </body>
</html></richcontent>
<node CREATED="1555442268867" ID="ID_1220289525" MODIFIED="1556597565754" TEXT="ausweichen">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <!--
        body { font-family: Cambria; font-size: 28pt }
        p { margin-top: 0 }
      -->
    

    <p>
      <font size="4">leftSpeed = aA * (rightBarrier - 1) + e;</font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">rightSpeed = aR * (leftBarrier - 1) + e;</font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
<icon BUILTIN="attach"/>
<icon BUILTIN="attach"/>
</node>
</node>
</node>
<node CREATED="1555442146122" ID="ID_285132072" MODIFIED="1556462264740" TEXT="s = 6">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      else
    </p>
  </body>
</html></richcontent>
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
<node CREATED="1555443150071" ID="ID_1404727423" MODIFIED="1555443158193" POSITION="right" TEXT="Kollision"/>
</node>
</map>
