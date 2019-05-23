<map version="1.0.1">
<!-- To view this file, download free mind mapping software FreeMind from http://freemind.sourceforge.net -->
<node CREATED="1555441858478" ID="ID_1136660202" MODIFIED="1555441885403" TEXT="messen, entscheiden, regeln">
<node CREATED="1555443143286" ID="ID_1820265369" MODIFIED="1555443149532" POSITION="right" TEXT="Abstand">
<node CREATED="1555442069002" ID="ID_330990518" MODIFIED="1555872047822" TEXT="asymetrisch">
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
<node CREATED="1555442511432" ID="ID_1868867466" MODIFIED="1556462297424" STYLE="fork" TEXT="s &lt;= 5">
<icon BUILTIN="button_ok"/>
<node CREATED="1555442111461" ID="ID_1177655817" MODIFIED="1555871134622" TEXT="&#x2206;2">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">1 : 3 </font>
    </p>
    <p>
      <font size="4">2 : 4 </font>
    </p>
    <p>
      <font size="4">3 : 5 </font>
    </p>
    <p>
      <font size="4">4 : 6 </font>
    </p>
    <p>
      <font size="4">&#160;</font>
    </p>
    <p>
      <font size="4">? abs(leftBarrier - rightBarrier) &gt; 1</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_cancel"/>
<node CREATED="1555442280253" ID="ID_608521" MODIFIED="1555872490726" TEXT="ignorieren">
<icon BUILTIN="button_cancel"/>
</node>
</node>
<node CREATED="1555442095366" ID="ID_1075527233" MODIFIED="1556462081958" TEXT="&#x2206;1">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">0 : 1 </font>
    </p>
    <p>
      <font size="4">1 : 2 </font>
    </p>
    <p>
      <font size="4">2 : 3 </font>
    </p>
    <p>
      <font size="4">3 : 4 </font>
    </p>
    <p>
      <font size="4">4 : 5 </font>
    </p>
    <p>
      <font size="4">&#160;</font>
    </p>
    <p>
      <font size="4">? abs(leftBarrier - rightBarrier) == 1</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_cancel"/>
</node>
<node CREATED="1556461993232" ID="ID_316459498" MODIFIED="1556462152611" TEXT="l &gt; r">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">? leftBarrier &gt; rightBarrier</font>
    </p>
  </body>
</html></richcontent>
<node CREATED="1555442268867" ID="ID_1058036249" MODIFIED="1556462217677" TEXT="ausweichen">
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
</node>
</node>
<node CREATED="1556462012102" ID="ID_157533692" MODIFIED="1556462164314" TEXT="r &gt; l">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">else</font>
    </p>
  </body>
</html></richcontent>
<node CREATED="1555442268867" ID="ID_1220289525" MODIFIED="1558631304592" TEXT="ausweichen">
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
  </body>
</html>
</richcontent>
<icon BUILTIN="button_ok"/>
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
<node CREATED="1555442258170" ID="ID_1443366646" MODIFIED="1556294365076" TEXT="wenden">
<richcontent TYPE="NOTE"><html>
  <head>
    
  </head>
  <body>
    <p>
      <font size="4">? barrierIsLeft ( </font>
    </p>
    <p>
      <font size="4">leftSpeed = turnSpeed; </font>
    </p>
    <p>
      <font size="4">rightSpeed = 0; </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">) </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">&#160;</font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">else ( </font>
    </p>
    <font size="4">leftSpeed = 0; </font>

    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">rightSpeed = turnSpeed; </font>
    </p>
    <p style="margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; text-indent: 0px">
      <font size="4">)&#160; </font>
    </p>
    <p>
      <font size="4">&#160;</font>
    </p>
  </body>
</html></richcontent>
<icon BUILTIN="button_ok"/>
</node>
</node>
</node>
<node CREATED="1555442041869" ID="ID_1639016630" MODIFIED="1555693379567" TEXT="symetrisch">
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
<node CREATED="1555442244772" ID="ID_1232303823" MODIFIED="1556596569865" TEXT="regeln">
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
</node>
</node>
</node>
</node>
<node CREATED="1555443150071" ID="ID_1404727423" MODIFIED="1555443158193" POSITION="right" TEXT="Kollision"/>
</node>
</map>
