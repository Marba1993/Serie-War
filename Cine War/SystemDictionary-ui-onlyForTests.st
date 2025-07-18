'From Cuis 5.0 of 7 November 2016 [latest update: #3292] on 12 May 2018 at 7:15:35 pm'!


!SystemDictionary methodsFor: 'ui' stamp: 'jmv 5/25/2014 15:54'!
beep
	"
	Smalltalk beep
	"
	Preferences soundsEnabled ifTrue: [
		Smalltalk
			at: #SampledSound
			ifPresent: [ :cls | cls beep ]
			ifAbsent: [ self primitiveBeep ]]! !

!SystemDictionary methodsFor: 'ui' stamp: 'LW 5/12/2018 19:14:56'!
confirmRemovalOf: aSelector on: aClass 
	"Determine if it is okay to remove the given selector. Answer 1 if it  
	should be removed, 2 if it should be removed followed by a senders  
	browse, and 3 if it should not be removed."
	| count aMenu answer caption allCalls |
	allCalls _ self allCallsOn: aSelector.
	(count _ allCalls size) = 0
		ifTrue: [(aClass superclass = TestCase) ifTrue: [(self confirm: '¿Realmente desea borrar este test?') ifTrue: [^1] ifFalse: [^3]] ifFalse: [^1]].
	"no senders -- let the removal happen without warning"
	count = 1
		ifTrue: [(allCalls first actualClass == aClass
					and: [allCalls first methodSymbol == aSelector])
				ifTrue: [^ 1]].
	"only sender is itself"
	aMenu _ PopUpMenu labels: 'Remove it
Remove, then browse senders
Don''t remove, but show me those senders
Forget it -- do nothing -- sorry I asked'.
	caption _ 'This message has ' , count printString , ' sender'.
	count > 1
		ifTrue: [caption _ caption copyWith: $s].
	answer _ aMenu startUpWithCaption: caption.
	answer = 3
		ifTrue: [self
				browseMessageList: allCalls
				name: 'Senders of ' , aSelector
				autoSelect: aSelector keywords first].
	answer = 0
		ifTrue: [answer _ 3].
	"If user didn't answer, treat it as cancel"
	^ answer min: 3! !

!SystemDictionary methodsFor: 'ui' stamp: 'jmv 9/27/2016 21:33:56'!
globals
	"
	Smalltalk  globals
	"
	
	| globals |
	globals _ IdentityDictionary new.
	self associationsDo: [ :assoc |
		assoc value class isMeta not ifTrue: [ globals add: assoc ]].
	^globals! !

!SystemDictionary methodsFor: 'ui' stamp: 'jmv 4/12/2015 20:13'!
inspectGlobals
	"
	Smalltalk  inspectGlobals
	"

	self globals inspectWithLabel: 'The Globals'! !

!SystemDictionary methodsFor: 'ui' stamp: 'jmv 5/25/2014 15:49'!
primitiveBeep
	"Make a primitive beep. Not to be called directly."
	"
	Smalltalk primitiveBeep
	"

	<primitive: 140>
	self primitiveFailed! !
