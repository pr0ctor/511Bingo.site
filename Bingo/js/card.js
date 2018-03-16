 $(document).ready(function(e) { 
	$('td').click(function () {
		var cell = $(this),
			state = cell.data('state') || 'first';

		switch (state) {
			case 'first':
				cell.addClass('card-active');
				cell.data('state', 'second');
				break;
			case 'second':
				cell.removeClass('card-active');
				cell.data('state', 'first');
				break;
			default:
				break;
		}
	});
});