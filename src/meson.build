# update config.h
run_command('cp',
	['-u', 'config.def.h', 'config.h']
	)

# curl dependency
dep_curl = dependency('libcurl', version: '>=7.51.0')

# local dependencies
domains = ['animegallery.c', 'danbooru.c' , 'eshuushuu.c', 'gelbooru.c',
	'konachan.c', 'mangadrawing.c', 'sankakucomplex.c', 'yandere.c' ,
	'zerochan.c']

helpers = ['interface.c', 'parser.c', 'udload.c']

# ruiji executable
executable('ruiji',
	'ruiji.c', domains, helpers,
	dependencies : dep_curl,
	install: true
	)
