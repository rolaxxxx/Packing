# Packing



 Pirmas boundaries variantas skirtas pradines stadijos is failo skaitymui Mesh
 O antras supakuos erdve triju pradiniu daleliu pagrindu
 
 
 kitos mesh.json dalys nekinta
 
 
    "INPUT":{
        "TYPE":"STANDART",
		"filename":"Pradinis.vtk"
	},
    
    
    
    "INPUT":{
		"filename":"Pradinis.vtk"
	},
    
    
Pakuojant su pradine stadija reikia rinktis panasius sphere radius abejuose pakavimuose.
Pvz 0.003(radius min) ir 5e-05(radius min) kaip distribution minimumai jau bus netinkami 
nes search funkcija paims per dideli kieki aplinkui esanciu sferu ir programa is esmes 
uzstrigs ir normaliai nebepakuos
    
    
