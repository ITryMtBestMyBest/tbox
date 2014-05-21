/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "../../demo.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */ 
static tb_bool_t tb_demo_async_stream_zip_save_func(tb_size_t state, tb_hize_t offset, tb_hong_t size, tb_hize_t save, tb_size_t rate, tb_cpointer_t priv)
{
	// percent
	tb_size_t percent = 0;
	if (size > 0) percent = (offset * 100) / size;
	else if (state == TB_STATE_OK) percent = 100;

	// trace
	tb_trace_i("save: %llu bytes, rate: %lu bytes/s, percent: %lu%%, state: %s", save, rate, percent, tb_state_cstr(state));

	// exit wait
	if (state != TB_STATE_OK) tb_event_post((tb_handle_t)priv);

	// ok
	return tb_true;
}

/* //////////////////////////////////////////////////////////////////////////////////////
 * main
 */ 
tb_int_t tb_demo_stream_async_stream_zip_main(tb_int_t argc, tb_char_t** argv)
{
	// done
	tb_handle_t 		event = tb_null;
	tb_handle_t 		transfer = tb_null;
	tb_async_stream_t* 	istream = tb_null;
	tb_async_stream_t* 	ostream = tb_null;
	tb_async_stream_t* 	fstream = tb_null;
	do
	{
		// init event
		event = tb_event_init();
		tb_assert_and_check_break(event);

		// init istream
		istream = tb_async_stream_init_from_url(tb_aicp(), argv[1]);
		tb_assert_and_check_break(istream);

		// init ostream
		ostream = tb_async_stream_init_from_file(tb_aicp(), argv[2], TB_FILE_MODE_RW | TB_FILE_MODE_CREAT | TB_FILE_MODE_BINARY | TB_FILE_MODE_TRUNC);
		tb_assert_and_check_break(ostream);

		// filter istream or ostream?
		tb_async_stream_t* iostream = istream;
//		tb_async_stream_t* iostream = ostream;

		// init fstream
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_RLC, TB_ZIP_ACTION_INFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_RLC, TB_ZIP_ACTION_DEFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_ZLIB, TB_ZIP_ACTION_INFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_ZLIB, TB_ZIP_ACTION_DEFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_GZIP, TB_ZIP_ACTION_INFLATE);
		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_GZIP, TB_ZIP_ACTION_DEFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_ZLIBRAW, TB_ZIP_ACTION_INFLATE);
//		fstream = tb_async_stream_init_filter_from_zip(iostream, TB_ZIP_ALGO_ZLIBRAW, TB_ZIP_ACTION_DEFLATE);
		tb_assert_and_check_break(fstream);

		// init transfer
		if (iostream == istream) transfer = tb_transfer_init_aa(fstream, ostream, 0);
		else transfer = tb_transfer_init_aa(istream, fstream, 0);
		tb_assert_and_check_break(transfer);

		// limit rate
//		tb_transfer_limitrate(transfer, 4096);

		// open and save transfer
		if (!tb_transfer_open_save(transfer, tb_demo_async_stream_zip_save_func, event)) break;

		// wait it
		tb_event_wait(event, -1);

	} while (0);

	// exit transfer
	if (transfer) tb_transfer_exit(transfer);
	transfer = tb_null;

	// exit fstream
	if (fstream) tb_async_stream_exit(fstream);
	fstream = tb_null;

	// exit istream
	if (istream) tb_async_stream_exit(istream);
	istream = tb_null;

	// exit ostream
	if (ostream) tb_async_stream_exit(ostream);
	ostream = tb_null;

	// exit event
	if (event) tb_event_exit(event);
	event = tb_null;
	return 0;
}
