CSP_DEFINE_TASK(thread_func) {
    csp_log_info("Thread started");
    thread_executed = true;
    csp_sleep_ms(10000); // safty - ensure process terminates
    exit(1);
    return CSP_TASK_RETURN;
}