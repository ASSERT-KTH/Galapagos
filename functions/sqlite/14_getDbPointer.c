static int getDbPointer(Tcl_Interp *interp, Tcl_Obj *pObj, sqlite3 **pDb){
  Tcl_CmdInfo info;
  if( 0==Tcl_GetCommandInfo(interp, Tcl_GetString(pObj), &info) ){
    Tcl_AppendResult(interp, "no such handle: ", Tcl_GetString(pObj), 0);
    return TCL_ERROR;
  }
  *pDb = *(sqlite3 **)info.objClientData;
  return TCL_OK;
}