function decorate()
{
    $('<h1> Space Game </h1>').appendTo('body');
	$("#jeu").css('display', 'none');
}
decorate()


var button = document.getElementById("Button");
button.setAttribute("onclick", "affiche_div()");

function affiche_div()
{
	var user = $('#Name').val();
	var pass = $('#Password').val();
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/players/login',
	xhrFields: { withCredentials: true },
	type : 'POST',
	data : {"username": user,
			"password": pass},
	success : function() {$("#connexion").css('display', 'none');
	$("#jeu").css('display', 'block');
	interval();},
	error : function() {alert('bad bitches')}
	})
}

function interval()
{
	LEVELUP_fact();
	LEVELUP_Metal();
	LEVELUP_Cristal();
	info_metal();
	info_crystal();
	info_factory();
	setInterval(function(){
			info_metal();
			info_crystal();
			info_factory();
	}, 1000);
}

var deco = document.getElementById("Logout");
deco.setAttribute("onclick", "deconexion()");

function deconexion()
{
	
	$.post ('http://163.5.245.219:3000/api/1/players/logout')
	
	$("#jeu").css('display', 'none');
	$("#connexion").css('display', 'block');
}

/*La fonction marche :0*/
function info_metal()
{
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/metalmines',
	xhrFields: { withCredentials: true },
	type : 'GET',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	dataType : "json",
	success : function(data){
			$($('p', '#lvl')[0]).text("Lvl " + data['level']);
			$($('p', '#ressources')[0]).text("Production " + data['production']);
			$($('p', '#ressources')[1]).text("Reserves " + data['amount']);
			$($('p', '#infoMine')[0]).text("Next Lvl: Metal=> " + data.costNext.metal);
			$($('p', '#infoMine')[1]).text("Next Lvl: Crystal=> " + data.costNext.crystal);}
			})
}

function info_crystal()
{
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/crystalmines',
	xhrFields: { withCredentials: true },
	type : 'GET',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	dataType : "json",
	success : function(data){
			$($('p', '#lvl2')[0]).text("Lvl " + data['level']);
			$($('p', '#ressources2')[0]).text("Production " + data['production']);
			$($('p', '#ressources2')[1]).text("Reserves " + data['amount']);
			$($('p', '#infoMine2')[0]).text("Next Lvl: Metal=> " + data.costNext.metal);
			$($('p', '#infoMine2')[1]).text("Next Lvl: Crystal=> " + data.costNext.crystal);				}
			})	
}

function info_factory()
{
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/factorys',
	xhrFields: { withCredentials: true },
	type : 'GET',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	dataType : "json",
	success : function(data){
			$($('p', '#lvlUP')[0]).text("Lvl " + data['level']);
			$("#en-cours").html("<p id='test'>" + data.queue +"</p>").show();
			$($('p', '#infoFact')[0]).text("Next Lvl: Metal=> " + data.costNext.metal);
			$($('p', '#infoFact')[1]).text("Next Lvl: Crystal=> " + data.costNext.crystal);}
			})	
}


function LEVELUP_Metal()
{
	$('#nvmUP').click(function(){
	
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/metalmines/levelUp ',
	xhrFields: { withCredentials: true },
	type : 'PUT',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	success : function(){
		alert('Level UP')
		},
		error : function(){
		alert('ATTENDEZ')
				}
		 	});
});

}

function LEVELUP_Cristal()
{
	$('#nvmUP2').click(function(){
	
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/crystalmines/levelUp ',
	xhrFields: { withCredentials: true },
	type : 'PUT',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	success : function(){
		alert('Level UP')
		},
		error : function(){
		alert('ATTENDEZ')
				}
		 	});
});

}

function LEVELUP_fact()
{
	$('#nvUUP').click(function(){
	
	$.ajax({
	url : 'http://163.5.245.219:3000/api/1/factorys/levelUp ',
	xhrFields: { withCredentials: true },
	type : 'PUT',
	data : {"username": "mohamd_y@etna-alternance.net",
			"password": "TaZY8rg3"},
	success : function(){
		alert('Level UP')
		},
		error : function(){
		alert('ATTENDEZ')
				}
		 	});
});

}

