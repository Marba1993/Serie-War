'From Cuis 5.0 of 7 November 2016 [latest update: #3174] on 1 July 2018 at 9:37:40 pm'!
'Description *1.0 - Creacion del paquete filter.

*1.1 - Creacion de los protocolos test y setUp.

*1.2 - Creacion de objeto filter y los mensajes: 
		- notToHaveCondition. ( Testea que un filter nuevo no tenga condicion )
		- filteredCondition: ( Asigna una condicion a un filter )
		
*1.3 - Creacion de objetos FilterCollection , OpenFilterCollection , CloseFilterCollection y los mensajes:
		- toAdd: at: ( Agregar un objeto a una coleccion si pasa una condicion dada en el filter )
		- mensajes externos y privados.
		
*1.4 - Pasar todos los test.

*1.5 - Refactoring.

*1.6 - Refactoring y nuevos protocolos.

*1.7 - Nuevo mensaje toRemove: at: ( Borra un objeto de una coleccion si pasa la condicion dada a un Filter ).
		'!
!provides: 'Collection - Filter' 1 7!
!classDefinition: #FilterTest category: #'Collection - Filter'!
TestCase subclass: #FilterTest
	instanceVariableNames: 'unaColeccion unObjeto unaCondicion unFiltro'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'Collection - Filter'!
!classDefinition: 'FilterTest class' category: #'Collection - Filter'!
FilterTest class
	instanceVariableNames: 'unaCondicion unaColeccion unObjeto unFiltro'!

!classDefinition: #Filter category: #'Collection - Filter'!
Object subclass: #Filter
	instanceVariableNames: 'condition'
	classVariableNames: ''
	poolDictionaries: ''
	category: 'Collection - Filter'!
!classDefinition: 'Filter class' category: #'Collection - Filter'!
Filter class
	instanceVariableNames: ''!

!classDefinition: #FilterCollection category: #'Collection - Filter'!
Object subclass: #FilterCollection
	instanceVariableNames: ''
	classVariableNames: ''
	poolDictionaries: ''
	category: 'Collection - Filter'!
!classDefinition: 'FilterCollection class' category: #'Collection - Filter'!
FilterCollection class
	instanceVariableNames: ''!

!classDefinition: #CloseFilterCollection category: #'Collection - Filter'!
FilterCollection subclass: #CloseFilterCollection
	instanceVariableNames: ''
	classVariableNames: ''
	poolDictionaries: ''
	category: 'Collection - Filter'!
!classDefinition: 'CloseFilterCollection class' category: #'Collection - Filter'!
CloseFilterCollection class
	instanceVariableNames: ''!

!classDefinition: #OpenFilterCollection category: #'Collection - Filter'!
FilterCollection subclass: #OpenFilterCollection
	instanceVariableNames: ''
	classVariableNames: ''
	poolDictionaries: ''
	category: 'Collection - Filter'!
!classDefinition: 'OpenFilterCollection class' category: #'Collection - Filter'!
OpenFilterCollection class
	instanceVariableNames: ''!


!FilterTest methodsFor: 'setUp' stamp: 'MB 7/1/2018 21:24:47'!
setUp

	unaColeccion _ OrderedCollection new.
	
	unObjeto _ 7.
	
	unaCondicion _ [ :each | each > 4 ].
	
	unFiltro _ Filter filteredCondition: unaCondicion .! !

!FilterTest methodsFor: 'test' stamp: 'MB 6/30/2018 23:35:25'!
test001_UnFiltroNuevoNoTieneCondicion

	| unFiltroSinCondicion |
	
	unFiltroSinCondicion _ Filter new.

	Assert isTrue: unFiltroSinCondicion notToHaveCondition! !

!FilterTest methodsFor: 'test' stamp: 'MB 6/30/2018 23:29:23'!
test002_UnFiltroTieneUnaCondicion
	
	Assert isFalse: unFiltro notToHaveCondition! !

!FilterTest methodsFor: 'test' stamp: 'MB 6/30/2018 23:46:14'!
test003_UnFiltroAgregaUnObjectoALaColeccionSiPasaLaCondicion
	
	unFiltro toAdd: unObjeto at: unaColeccion .
	
	Assert isTrue: (unaColeccion includes: unObjeto )! !

!FilterTest methodsFor: 'test' stamp: 'MB 7/1/2018 00:38:32'!
test004_UnFiltroNoAgregaUnObjectoALaColeccionSiNoPasaLaCondicion
	
	| otraCondicion |
	
	otraCondicion _ [ :each | each > 7 ].
	
	unFiltro filteredCondition: otraCondicion .
	
	unFiltro toAdd: unObjeto at: unaColeccion .
	
	Assert isFalse: (unaColeccion includes: unObjeto )! !

!FilterTest methodsFor: 'test' stamp: 'MB 7/1/2018 21:23:41'!
test005_UnFiltroRemoveUnObjectoALaColeccionSiPasaLaCondicion
	
	| otroObjecto  |
	
	otroObjecto _ 6.
	
	unFiltro toAdd: unObjeto  at: unaColeccion .
	
	unFiltro toAdd: otroObjecto  at: unaColeccion .
	
	unFiltro toRemove: unObjeto at: unaColeccion .
	
	Assert isFalse: (unaColeccion includes: unObjeto )! !

!FilterTest methodsFor: 'test' stamp: 'MB 7/1/2018 21:30:19'!
test006_UnFiltroNoRemoveUnObjectoALaColeccionSiNoPasaLaCondicion
	
	unFiltro toAdd: unObjeto at: unaColeccion .
	
	unFiltro filteredCondition: [ :each | each > 7 ].
	
	unFiltro toRemove: unObjeto at: unaColeccion .
	
	Assert isTrue: (unaColeccion includes: unObjeto )! !

!Filter methodsFor: 'private - filter' stamp: 'MB 7/1/2018 00:11:12'!
filterStep: aObject 
	
	^ condition value: aObject ! !

!Filter methodsFor: 'condition' stamp: 'MB 6/30/2018 23:19:14'!
filteredCondition: aCondition
	
	condition _ aCondition ! !

!Filter methodsFor: 'private - filter' stamp: 'MB 7/1/2018 00:09:34'!
notFilterStep: aObject 
	
	^ (condition value: aObject ) not! !

!Filter methodsFor: 'testing - filter' stamp: 'MB 6/30/2018 23:16:31'!
notToHaveCondition
	
	^ condition isNil.! !

!Filter methodsFor: 'private - filter' stamp: 'MB 6/30/2018 23:59:38'!
passingCondition: aObject 
	
	^ FilterCollection conditionObject: aObject of: self! !

!Filter methodsFor: 'adding' stamp: 'MB 6/30/2018 23:55:11'!
toAdd: aObject at: aCollection 
	
	(self passingCondition: aObject ) add: aObject for: aCollection .! !

!Filter methodsFor: 'removing' stamp: 'MB 7/1/2018 21:16:51'!
toRemove: aObject at: aCollection 
	(self passingCondition: aObject ) remove: aObject for: aCollection .! !

!Filter class methodsFor: 'condition creation' stamp: 'MB 6/30/2018 23:34:11'!
filteredCondition: aCondition 
	
	^ self toCreateInstance filteredCondition: aCondition ! !

!Filter class methodsFor: 'instance creation' stamp: 'MB 6/30/2018 23:34:34'!
toCreateInstance
	
	^ self new! !

!FilterCollection class methodsFor: 'instance creation' stamp: 'MB 7/1/2018 00:05:15'!
conditionObject: aObject of: aFilter 
	
	^( self allSubclasses detect: [:aCondition | aCondition canTakeCharge: aObject for: aFilter ]) new.! !

!CloseFilterCollection methodsFor: 'add Object' stamp: 'MB 7/1/2018 00:39:44'!
add: aObject for: aCollection 
	
	" No hace nada si no paso la condicion"! !

!CloseFilterCollection methodsFor: 'Remove Object' stamp: 'MB 7/1/2018 21:26:49'!
remove: aObject for: aCollection 
	
	" No hace nada si no pasa la condicion "! !

!CloseFilterCollection class methodsFor: 'status - object' stamp: 'MB 7/1/2018 00:08:21'!
canTakeCharge: aObject for: aFilter 
	
	^ aFilter notFilterStep: aObject ! !

!OpenFilterCollection methodsFor: 'add Object' stamp: 'MB 7/1/2018 00:12:22'!
add: aObject for: aCollection 
	
	aCollection add: aObject ! !

!OpenFilterCollection methodsFor: 'remove Object' stamp: 'MB 7/1/2018 21:17:48'!
remove: aObject for: aCollection 
	
	aCollection remove: aObject ! !

!OpenFilterCollection class methodsFor: 'status - object' stamp: 'MB 7/1/2018 00:10:36'!
canTakeCharge: aObject for: aFilter 
	
	^ aFilter filterStep: aObject ! !
