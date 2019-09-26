# Packing



 Pirmas boundaries variantas skirtas pradines stadijos is failo skaitymui Mesh
 O antras supakuos erdve triju pradiniu daleliu pagrindu
 
 
 kitos mesh.json dalys nekinta
 
 
    "BOUNDARIES":
		{
		"TYPE":"Mesh",
		"FILENAME":"cylinder_mesh.vtk",
		"MESH_INPUT":"MESH_FILE",
		"MESH_INPUT_FILE":"Mesh_rez.vtk"
		},
    
    
    
    "BOUNDARIES":
		{
		"TYPE":"Mesh",
		"FILENAME":"cylinder_mesh.vtk",
		
		},
    
    
    Pakuojant su pradine stadija reikia rinktis panasius sphere radius abejuose pakavimuose. Pvz 0.003(radius min) ir 5e-05(radius min) kaip distribution minimumai
    jau bus netinkami nes search funkcija paims per dideli kieki aplinkui esanciu sferu ir programa is esmes uzstrigs ir normaliai nebepakuos
    
    
