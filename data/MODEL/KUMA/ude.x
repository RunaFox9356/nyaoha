xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 79;
 1.00400;13.45020;0.00000;,
 2.02207;12.38166;-1.47253;,
 1.00400;12.38166;-2.08248;,
 1.00400;13.45020;0.00000;,
 2.44377;12.38166;0.00000;,
 1.00400;13.45020;0.00000;,
 2.02207;12.38166;1.47253;,
 1.00400;13.45020;0.00000;,
 1.00400;12.38166;2.08248;,
 1.00400;13.45020;0.00000;,
 -0.01406;12.38166;1.47253;,
 1.00400;13.45020;0.00000;,
 -0.43576;12.38166;-0.00000;,
 1.00400;13.45020;0.00000;,
 -0.01406;12.38166;-1.47253;,
 1.00400;13.45020;0.00000;,
 1.00400;12.38166;-2.08248;,
 2.88514;9.33870;-2.72089;,
 1.00400;9.33870;-3.84791;,
 3.66433;9.33870;0.00000;,
 2.88514;9.33870;2.72089;,
 1.00400;9.33870;3.84791;,
 -0.87714;9.33870;2.72089;,
 -1.65633;9.33870;-0.00000;,
 -0.87714;9.33870;-2.72089;,
 1.00400;9.33870;-3.84791;,
 3.46182;4.78458;-3.55501;,
 1.00400;4.78458;-5.02754;,
 4.47990;4.78458;0.00000;,
 3.46182;4.78458;3.55501;,
 1.00399;4.78458;5.02754;,
 -1.45382;4.78458;3.55501;,
 -2.47190;4.78458;-0.00000;,
 -1.45382;4.78458;-3.55501;,
 1.00400;4.78458;-5.02754;,
 3.66433;-0.58737;-3.84791;,
 1.00400;-0.58737;-5.44177;,
 4.76628;-0.58737;0.00000;,
 3.66433;-0.58737;3.84791;,
 1.00399;-0.58737;5.44177;,
 -1.65633;-0.58737;3.84791;,
 -2.75827;-0.58737;-0.00000;,
 -1.65633;-0.58737;-3.84791;,
 1.00400;-0.58737;-5.44177;,
 3.46182;-5.95932;-3.55501;,
 1.00400;-5.95932;-5.02754;,
 4.47990;-5.95932;0.00000;,
 3.46182;-5.95932;3.55501;,
 1.00399;-5.95932;5.02754;,
 -1.45382;-5.95932;3.55501;,
 -2.47190;-5.95932;-0.00000;,
 -1.45382;-5.95932;-3.55501;,
 1.00400;-5.95932;-5.02754;,
 2.88514;-10.51343;-2.72089;,
 1.00400;-10.51343;-3.84791;,
 3.66433;-10.51343;0.00000;,
 2.88514;-10.51343;2.72089;,
 1.00400;-10.51343;3.84791;,
 -0.87714;-10.51343;2.72089;,
 -1.65633;-10.51343;-0.00000;,
 -0.87714;-10.51343;-2.72089;,
 1.00400;-10.51343;-3.84791;,
 2.02207;-13.55640;-1.47253;,
 1.00400;-13.55640;-2.08248;,
 2.44377;-13.55640;0.00000;,
 2.02207;-13.55640;1.47253;,
 1.00400;-13.55640;2.08248;,
 -0.01406;-13.55640;1.47253;,
 -0.43576;-13.55640;-0.00000;,
 -0.01406;-13.55640;-1.47253;,
 1.00400;-13.55640;-2.08248;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;,
 1.00400;-14.62494;-0.00000;;
 
 64;
 3;0,1,2;,
 3;3,4,1;,
 3;5,6,4;,
 3;7,8,6;,
 3;9,10,8;,
 3;11,12,10;,
 3;13,14,12;,
 3;15,16,14;,
 4;2,1,17,18;,
 4;1,4,19,17;,
 4;4,6,20,19;,
 4;6,8,21,20;,
 4;8,10,22,21;,
 4;10,12,23,22;,
 4;12,14,24,23;,
 4;14,16,25,24;,
 4;18,17,26,27;,
 4;17,19,28,26;,
 4;19,20,29,28;,
 4;20,21,30,29;,
 4;21,22,31,30;,
 4;22,23,32,31;,
 4;23,24,33,32;,
 4;24,25,34,33;,
 4;27,26,35,36;,
 4;26,28,37,35;,
 4;28,29,38,37;,
 4;29,30,39,38;,
 4;30,31,40,39;,
 4;31,32,41,40;,
 4;32,33,42,41;,
 4;33,34,43,42;,
 4;36,35,44,45;,
 4;35,37,46,44;,
 4;37,38,47,46;,
 4;38,39,48,47;,
 4;39,40,49,48;,
 4;40,41,50,49;,
 4;41,42,51,50;,
 4;42,43,52,51;,
 4;45,44,53,54;,
 4;44,46,55,53;,
 4;46,47,56,55;,
 4;47,48,57,56;,
 4;48,49,58,57;,
 4;49,50,59,58;,
 4;50,51,60,59;,
 4;51,52,61,60;,
 4;54,53,62,63;,
 4;53,55,64,62;,
 4;55,56,65,64;,
 4;56,57,66,65;,
 4;57,58,67,66;,
 4;58,59,68,67;,
 4;59,60,69,68;,
 4;60,61,70,69;,
 3;63,62,71;,
 3;62,64,72;,
 3;64,65,73;,
 3;65,66,74;,
 3;66,67,75;,
 3;67,68,76;,
 3;68,69,77;,
 3;69,70,78;;
 
 MeshMaterialList {
  5;
  64;
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3,
  3;;
  Material {
   0.800000;0.498824;0.178824;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.765490;0.351373;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.530196;0.100392;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.640000;0.392157;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  66;
  -0.000002;1.000000;-0.000000;,
  -0.000001;0.733439;-0.679755;,
  0.599435;0.666406;-0.443374;,
  0.790181;0.612873;0.000000;,
  0.599435;0.666406;0.443375;,
  -0.000001;0.733439;0.679755;,
  -0.599437;0.666405;0.443373;,
  -0.790182;0.612872;-0.000000;,
  -0.599437;0.666405;-0.443373;,
  -0.000001;0.381452;-0.924389;,
  0.754107;0.320302;-0.573350;,
  0.961181;0.275918;0.000000;,
  0.754107;0.320302;0.573350;,
  -0.000001;0.381452;0.924389;,
  -0.754108;0.320302;0.573348;,
  -0.961181;0.275918;-0.000000;,
  -0.754108;0.320302;-0.573348;,
  0.508742;0.141868;-0.849149;,
  0.786358;0.135568;-0.602712;,
  0.993364;0.115011;0.000000;,
  0.786358;0.135568;0.602712;,
  0.508742;0.141868;0.849150;,
  -0.786359;0.135568;0.602711;,
  -0.993364;0.115010;0.000000;,
  -0.786359;0.135568;-0.602711;,
  0.513940;-0.000000;-0.857826;,
  0.793172;-0.000000;-0.608998;,
  1.000000;-0.000000;0.000000;,
  0.793172;-0.000000;0.608998;,
  0.513940;-0.000000;0.857826;,
  -0.793173;-0.000000;0.608996;,
  -1.000000;-0.000000;-0.000000;,
  -0.793173;-0.000000;-0.608997;,
  0.508742;-0.141868;-0.849149;,
  0.786358;-0.135569;-0.602712;,
  0.993364;-0.115011;-0.000000;,
  0.786358;-0.135569;0.602712;,
  0.508742;-0.141868;0.849150;,
  -0.786359;-0.135568;0.602711;,
  -0.993364;-0.115010;-0.000000;,
  -0.786359;-0.135568;-0.602711;,
  0.188124;-0.415475;-0.889938;,
  0.754107;-0.320302;-0.573350;,
  0.961181;-0.275918;-0.000000;,
  0.754107;-0.320302;0.573350;,
  0.188124;-0.415475;0.889938;,
  -0.754108;-0.320302;0.573348;,
  -0.961181;-0.275918;-0.000000;,
  -0.754108;-0.320302;-0.573348;,
  -0.000001;-0.733438;-0.679756;,
  0.599435;-0.666405;-0.443375;,
  0.790182;-0.612873;0.000000;,
  0.599435;-0.666405;0.443375;,
  -0.000001;-0.733438;0.679756;,
  -0.599437;-0.666404;0.443374;,
  -0.790183;-0.612871;-0.000000;,
  -0.599437;-0.666404;-0.443374;,
  -0.000002;-1.000000;0.000000;,
  -0.508744;0.141868;0.849148;,
  -0.508744;0.141868;-0.849149;,
  -0.513942;-0.000000;0.857825;,
  -0.513942;-0.000000;-0.857825;,
  -0.508744;-0.141868;0.849148;,
  -0.508744;-0.141868;-0.849149;,
  -0.501706;-0.216908;0.837402;,
  -0.501706;-0.216908;-0.837402;;
  64;
  3;0,2,1;,
  3;0,3,2;,
  3;0,4,3;,
  3;0,5,4;,
  3;0,6,5;,
  3;0,7,6;,
  3;0,8,7;,
  3;0,1,8;,
  4;1,2,10,9;,
  4;2,3,11,10;,
  4;3,4,12,11;,
  4;4,5,13,12;,
  4;5,6,14,13;,
  4;6,7,15,14;,
  4;7,8,16,15;,
  4;8,1,9,16;,
  4;9,10,18,17;,
  4;10,11,19,18;,
  4;11,12,20,19;,
  4;12,13,21,20;,
  4;13,14,22,58;,
  4;14,15,23,22;,
  4;15,16,24,23;,
  4;16,9,59,24;,
  4;17,18,26,25;,
  4;18,19,27,26;,
  4;19,20,28,27;,
  4;20,21,29,28;,
  4;58,22,30,60;,
  4;22,23,31,30;,
  4;23,24,32,31;,
  4;24,59,61,32;,
  4;25,26,34,33;,
  4;26,27,35,34;,
  4;27,28,36,35;,
  4;28,29,37,36;,
  4;60,30,38,62;,
  4;30,31,39,38;,
  4;31,32,40,39;,
  4;32,61,63,40;,
  4;33,34,42,41;,
  4;34,35,43,42;,
  4;35,36,44,43;,
  4;36,37,45,44;,
  4;62,38,46,64;,
  4;38,39,47,46;,
  4;39,40,48,47;,
  4;40,63,65,48;,
  4;41,42,50,49;,
  4;42,43,51,50;,
  4;43,44,52,51;,
  4;44,45,53,52;,
  4;45,46,54,53;,
  4;46,47,55,54;,
  4;47,48,56,55;,
  4;48,41,49,56;,
  3;49,50,57;,
  3;50,51,57;,
  3;51,52,57;,
  3;52,53,57;,
  3;53,54,57;,
  3;54,55,57;,
  3;55,56,57;,
  3;56,49,57;;
 }
 MeshTextureCoords {
  79;
  0.062500;0.000000;,
  0.125000;0.125000;,
  0.000000;0.125000;,
  0.187500;0.000000;,
  0.250000;0.125000;,
  0.312500;0.000000;,
  0.375000;0.125000;,
  0.437500;0.000000;,
  0.500000;0.125000;,
  0.562500;0.000000;,
  0.625000;0.125000;,
  0.687500;0.000000;,
  0.750000;0.125000;,
  0.812500;0.000000;,
  0.875000;0.125000;,
  0.937500;0.000000;,
  1.000000;0.125000;,
  0.125000;0.250000;,
  0.000000;0.250000;,
  0.250000;0.250000;,
  0.375000;0.250000;,
  0.500000;0.250000;,
  0.625000;0.250000;,
  0.750000;0.250000;,
  0.875000;0.250000;,
  1.000000;0.250000;,
  0.125000;0.375000;,
  0.000000;0.375000;,
  0.250000;0.375000;,
  0.375000;0.375000;,
  0.500000;0.375000;,
  0.625000;0.375000;,
  0.750000;0.375000;,
  0.875000;0.375000;,
  1.000000;0.375000;,
  0.125000;0.500000;,
  0.000000;0.500000;,
  0.250000;0.500000;,
  0.375000;0.500000;,
  0.500000;0.500000;,
  0.625000;0.500000;,
  0.750000;0.500000;,
  0.875000;0.500000;,
  1.000000;0.500000;,
  0.125000;0.625000;,
  0.000000;0.625000;,
  0.250000;0.625000;,
  0.375000;0.625000;,
  0.500000;0.625000;,
  0.625000;0.625000;,
  0.750000;0.625000;,
  0.875000;0.625000;,
  1.000000;0.625000;,
  0.125000;0.750000;,
  0.000000;0.750000;,
  0.250000;0.750000;,
  0.375000;0.750000;,
  0.500000;0.750000;,
  0.625000;0.750000;,
  0.750000;0.750000;,
  0.875000;0.750000;,
  1.000000;0.750000;,
  0.125000;0.875000;,
  0.000000;0.875000;,
  0.250000;0.875000;,
  0.375000;0.875000;,
  0.500000;0.875000;,
  0.625000;0.875000;,
  0.750000;0.875000;,
  0.875000;0.875000;,
  1.000000;0.875000;,
  0.062500;1.000000;,
  0.187500;1.000000;,
  0.312500;1.000000;,
  0.437500;1.000000;,
  0.562500;1.000000;,
  0.687500;1.000000;,
  0.812500;1.000000;,
  0.937500;1.000000;;
 }
}
